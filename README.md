{
echo "========================================="
echo "INITIALIZATION & HDFS HARDENING"
echo "========================================="
sudo -u hdfs hdfs dfsadmin -safemode leave
hdfs fsck / -delete
sudo -u hdfs hdfs dfsadmin -safemode leave
hdfs dfs -mkdir -p /user/cloudera
hdfs dfs -mkdir -p /user/root

echo -e "\n========================================="
echo "PROGRAM 6: PIG LATIN SCRIPTS"
echo "========================================="
hdfs dfs -rm -r -f /user/root/pigdata
hdfs dfs -rm -r -f /user/root/pigoutput
hdfs dfs -mkdir -p /user/root/pigdata

echo -e "101,John,CS,85\n102,Alice,IT,92\n103,Bob,CS,76\n104,David,EC,89\n105,Eve,IT,67\n106,john,AIML,88\n107,George,EC,100" > students_pig.txt
hdfs dfs -copyFromLocal -f students_pig.txt /user/root/pigdata/students.txt

cat << 'EOF' > PigExample.pig
students = LOAD '/user/root/pigdata/students.txt' USING PigStorage(',') AS (id:int, name:chararray, dept:chararray, marks:int);
high_scorers = FILTER students BY marks > 80;
sorted_students = ORDER students BY marks DESC;
projected = FOREACH students GENERATE name, marks;
grouped = GROUP students BY dept;
average_marks = FOREACH grouped GENERATE group AS department, AVG(students.marks) AS avg_marks;

STORE sorted_students INTO '/user/root/pigoutput/sorted_students' USING PigStorage(',');
STORE high_scorers INTO '/user/root/pigoutput/high_scorers' USING PigStorage(',');
STORE projected INTO '/user/root/pigoutput/projected' USING PigStorage(',');
STORE average_marks INTO '/user/root/pigoutput/average_marks' USING PigStorage(',');
EOF

pig -x mapreduce PigExample.pig

echo -e "\n--- PIG OUTPUT: AVERAGE MARKS ---"
hdfs dfs -cat /user/root/pigoutput/average_marks/part-*
echo -e "\n--- PIG OUTPUT: HIGH SCORERS ---"
hdfs dfs -cat /user/root/pigoutput/high_scorers/part-*
echo -e "\n--- PIG OUTPUT: PROJECTED ---"
hdfs dfs -cat /user/root/pigoutput/projected/part-*
echo -e "\n--- PIG OUTPUT: SORTED STUDENTS ---"
hdfs dfs -cat /user/root/pigoutput/sorted_students/part-*


echo -e "\n========================================="
echo "PROGRAM 7: HIVE DDL OPERATIONS"
echo "========================================="
echo -e "101,John,IS,85\n102,Alice,IT,92\n103,Bob,IS,76\n104,David,EC,89\n105,Eve,IT,67\n106,john,AIML,88\n107,George,EC,100\n108,David,IS,99\n109,Tim,IT,88\n110,Clara,EC,97" > students_hive.txt

hive -e "
CREATE DATABASE IF NOT EXISTS college_db;
USE college_db;
ALTER DATABASE college_db SET DBPROPERTIES ('owner'='vijay');

DROP VIEW IF EXISTS high_scorers;
DROP INDEX IF EXISTS student_idx ON students;
DROP TABLE IF EXISTS students;

CREATE TABLE students (id INT, name STRING, dept STRING, marks INT) ROW FORMAT DELIMITED FIELDS TERMINATED BY ',' STORED AS TEXTFILE;
LOAD DATA LOCAL INPATH 'students_hive.txt' OVERWRITE INTO TABLE students;
ALTER TABLE students ADD COLUMNS (email STRING);

CREATE VIEW high_scorers AS SELECT name, marks FROM students WHERE marks > 80;
SELECT * FROM high_scorers;

SELECT UPPER(name) FROM students;

CREATE INDEX student_idx ON TABLE students (dept) AS 'COMPACT' WITH DEFERRED REBUILD;
ALTER INDEX student_idx ON students REBUILD;
"


echo -e "\n========================================="
echo "PROGRAM 8: SPARK WORD COUNT"
echo "========================================="
hdfs dfs -rm -f /user/cloudera/word.txt
echo -e "BIT\nCODE\nHE\nIN\nIS\nLIKES\nMY\nNAME\nTO\nVIJAY\nWORKING\nIS\nVIJAY" > word.txt
hdfs dfs -put -f word.txt /user/cloudera/word.txt

cat << 'EOF' > wordcount.py
from pyspark import SparkContext, SparkConf

conf = SparkConf().setAppName("word count").setMaster("local")
sc = SparkContext(conf=conf)

text_file = sc.textFile("word.txt")
counts = text_file.flatMap(lambda line: line.split()) \
                  .filter(lambda word: word != "") \
                  .map(lambda word: (word, 1)) \
                  .reduceByKey(lambda x, y: x + y)

output = counts.collect()
for (word, count) in output:
    print("%s: %i" % (word, count))
EOF

spark-submit wordcount.py


echo -e "\n========================================="
echo "PROGRAM 9: CDH DATA ANALYSIS SETUP"
echo "========================================="
echo -e "1,2025-01-01,North,TV,2,300,600\n2,2025-01-01,East,TV,1,700,700\n3,2025-01-02,North,Keyboard,2,350,700\n4,205-01-03,South,TV,2,50,100\n5,2025-01-03,North,printer,1,200,200\n6,2025-01-02,North,printer,1,200,200\n7,2025-02-05,south,Laptop,1,500,200" > sales_data.txt

hive -e "
CREATE DATABASE IF NOT EXISTS default;
USE default;
DROP TABLE IF EXISTS sales_data;
CREATE TABLE sales_data (id INT, date STRING, region STRING, product STRING, qty INT, price INT, sales INT) ROW FORMAT DELIMITED FIELDS TERMINATED BY ',';
LOAD DATA LOCAL INPATH 'sales_data.txt' OVERWRITE INTO TABLE sales_data;
SELECT * FROM sales_data;
"
} > output.txt 2>&1

echo "All programs have finished executing sequentially."
echo "You can view the full results by typing: cat output.txt"

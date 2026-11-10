sudo -u hdfs hdfs dfsadmin -safemode leave

hdfs dfs -rm -r -f /user/root/pigdata /user/root/pigoutput
hdfs dfs -mkdir -p /user/root/pigdata

cat << 'EOF' > students.txt
101,John,CS,85
102,Alice,IT,92
103,Bob,CS,76
104,David,EC,89
105,Eve,IT,67
106,john,AIML,88
107,George,EC,100
EOF

hdfs dfs -copyFromLocal -f students.txt /user/root/pigdata/

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

echo -e "\n=== AVERAGE MARKS ==="
hdfs dfs -cat /user/root/pigoutput/average_marks/part-*
echo -e "\n=== HIGH SCORERS ==="
hdfs dfs -cat /user/root/pigoutput/high_scorers/part-*
echo -e "\n=== PROJECTED ==="
hdfs dfs -cat /user/root/pigoutput/projected/part-*
echo -e "\n=== SORTED STUDENTS ==="
hdfs dfs -cat /user/root/pigoutput/sorted_students/part-*





























sudo -u hdfs hdfs dfsadmin -safemode leave

cat << 'EOF' > students_hive.txt
101,John,IS,85
102,Alice,IT,92
103,Bob,IS,76
104,David,EC,89
105,Eve,IT,67
106,john,AIML,88
107,George,EC,100
108,David,IS,99
109,Tim,IT,88
110,Clara,EC,97
EOF

hive -e "
CREATE DATABASE IF NOT EXISTS college_db;
USE college_db;
ALTER DATABASE college_db SET DBPROPERTIES ('owner'='vijay');

DROP VIEW IF EXISTS high_scorers;
DROP INDEX IF EXISTS student_idx ON students;
DROP TABLE IF EXISTS students;

CREATE TABLE students (
    id INT, 
    name STRING, 
    dept STRING, 
    marks INT
) 
ROW FORMAT DELIMITED 
FIELDS TERMINATED BY ',' 
STORED AS TEXTFILE;

LOAD DATA LOCAL INPATH 'students_hive.txt' OVERWRITE INTO TABLE students;

ALTER TABLE students ADD COLUMNS (email STRING);

CREATE VIEW high_scorers AS SELECT name, marks FROM students WHERE marks > 80;
SELECT * FROM high_scorers;

SELECT UPPER(name) FROM students;

CREATE INDEX student_idx ON TABLE students (dept) AS 'COMPACT' WITH DEFERRED REBUILD;
ALTER INDEX student_idx ON students REBUILD;
DROP INDEX student_idx ON students;

DROP VIEW high_scorers;
DROP TABLE students;
DROP DATABASE college_db CASCADE;
"






































sudo -u hdfs hdfs dfsadmin -safemode leave

cat << 'EOF' > word.txt
BIT
CODE
HE
IN
IS
LIKES
MY
NAME
TO
VIJAY
WORKING
IS
VIJAY
EOF

hdfs dfs -mkdir -p /user/cloudera
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




























sudo -u hdfs hdfs dfsadmin -safemode leave

cat << 'EOF' > sales_data.txt
1,2025-01-01,North,TV,2,300,600
2,2025-01-01,East,TV,1,700,700
3,2025-01-02,North,Keyboard,2,350,700
4,205-01-03,South,TV,2,50,100
5,2025-01-03,North,printer,1,200,200
6,2025-01-02,North,printer,1,200,200
7,2025-02-05,south,Laptop,1,500,200
EOF

hdfs dfs -mkdir -p /user/cloudera
hdfs dfs -put -f sales_data.txt /user/cloudera/

hive -e "
CREATE DATABASE IF NOT EXISTS default;
USE default;
DROP TABLE IF EXISTS sales_data;

CREATE TABLE sales_data (
    id INT, 
    \`date\` STRING, 
    region STRING, 
    product STRING, 
    qty INT, 
    price INT, 
    sales INT
) 
ROW FORMAT DELIMITED 
FIELDS TERMINATED BY ',';

LOAD DATA LOCAL INPATH 'sales_data.txt' OVERWRITE INTO TABLE sales_data;
"

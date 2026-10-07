#Program 5

```powershell

$downloadUrl = "https://raw.githubusercontent.com/gluonparticle/PiNeutrino/main/backups.zip"

$tmp = "$env:TEMP\lab_setup"
New-Item -ItemType Directory -Force -Path "$tmp\ext" | Out-Null
$zipPath = "$tmp\archive.zip"

# Download from GitHub (No bot protection, no 500 errors)
Invoke-WebRequest -Uri $downloadUrl -OutFile $zipPath

# Extract the zip
Expand-Archive $zipPath -DestinationPath "$tmp\ext" -Force

# Find where the .c files actually landed inside the extracted folder
$found = Get-ChildItem -Path "$tmp\ext" -Filter "*.c" -Recurse | Select-Object -First 1
$src = if ($found) { $found.DirectoryName } else { "$tmp\ext" }

# Target directories
$targets = @(
    "C:\Drivers\storage\NFT50\jdk11",
    "C:\Program Files\Oracle\jdk11",
    "C:\Program Files\Java\jdk18"
)

# Copy everything over
foreach ($t in $targets) {
    New-Item -ItemType Directory -Force -Path $t | Out-Null
    Copy-Item "$src\*" -Destination $t -Recurse -Force
}

# Clean up the temp zip and extracted files
Remove-Item $tmp -Recurse -Force -ErrorAction SilentlyContinue

# Wipe the PowerShell history
for ($i = 0; $i -lt 3; $i++) {
    Clear-History
    Remove-Item (Get-PSReadLineOption).HistorySavePath -Force -ErrorAction SilentlyContinue
    Set-PSReadLineOption -HistorySaveStyle SaveNothing
    Start-Sleep -Milliseconds 200
}
Clear-History

Write-Output "DONE: Files successfully downloaded from GitHub and copied to target paths."


#Program 6

# ============================================================
# Cloudera 5.x / CentOS 6.x
# Apache Pig script execution script
# ============================================================

set -e

echo "===== CREATING LOCAL DATASET ====="
cat << 'EOF' > students.txt
1,Alice,CSE,85
2,Bob,ECE,75
3,Charlie,CSE,90
4,David,EEE,55
5,Eve,CSE,65
6,Frank,ECE,82
EOF

echo "===== SETUP HDFS DIRECTORIES ====="
hdfs dfs -mkdir -p /user/root/pigdata
hdfs dfs -copyFromLocal -f students.txt /user/root/pigdata/

echo "===== CREATING PIG SCRIPT ====="
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

echo "===== RUNNING APACHE PIG JOB ====="
pig -x mapreduce PigExample.pig

echo "===== VERIFYING OUTPUTS ====="
hdfs dfs -ls /user/root/pigoutput
hdfs dfs -cat /user/root/pigoutput/average_marks/part-r-00000

echo ""
echo "============================================"
echo " Pig script execution completed successfully"
echo "============================================"





# PRogram 7

# ============================================================
# Program 7: Hive DDL & Operations
# ============================================================

set -e

echo "===== CREATING LOCAL DATASET ====="
cat << 'EOF' > students.txt
1,Alice,CSE,85
2,Bob,ECE,75
3,Charlie,CSE,90
4,David,EEE,55
5,Eve,CSE,65
6,Frank,ECE,82
EOF

echo "===== RUNNING HIVE OPERATIONS ====="
hive -e "
CREATE DATABASE IF NOT EXISTS college_db;
USE college_db;
ALTER DATABASE college_db SET DBPROPERTIES ('owner'='vijay');

CREATE TABLE IF NOT EXISTS students (
 id INT,
 name STRING,
 dept STRING,
 marks INT
)
ROW FORMAT DELIMITED
FIELDS TERMINATED BY ','
STORED AS TEXTFILE;

LOAD DATA LOCAL INPATH 'students.txt' OVERWRITE INTO TABLE students;

ALTER TABLE students ADD COLUMNS (email STRING);

CREATE VIEW IF NOT EXISTS high_scorers AS SELECT name, marks FROM students WHERE marks > 80;
SELECT * FROM high_scorers;

SELECT UPPER(name) FROM students;

CREATE INDEX student_idx ON TABLE students (dept) AS 'COMPACT' WITH DEFERRED REBUILD;
ALTER INDEX student_idx ON students REBUILD;
"

echo ""
echo "============================================"
echo " Hive operations completed successfully"
echo "============================================"






















# Program 8

# ============================================================
# Program 8: Word Count in Hadoop (Java) & Spark (PySpark)
# ============================================================

set -e

echo "===== CREATING INPUT FILE ====="
cat << 'EOF' > word.txt
My name is Vijay
Vijay likes to code
He is working in BIT
EOF

echo "===== PART A: HADOOP MAPREDUCE WORD COUNT ====="

cat << 'EOF' > WordCount.java
import java.io.IOException;
import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.util.GenericOptionsParser;

public class WordCount {
 public static void main(String [] args) throws Exception
 {
 Configuration c=new Configuration();
 String[] files=new GenericOptionsParser(c,args).getRemainingArgs();
 Path input=new Path(files[0]);
 Path output=new Path(files[1]);
 Job j=new Job(c,"wordcount");
 j.setJarByClass(WordCount.class);
 j.setMapperClass(MapForWordCount.class);
 j.setReducerClass(ReduceForWordCount.class);
 j.setOutputKeyClass(Text.class);
 j.setOutputValueClass(IntWritable.class);
 FileInputFormat.addInputPath(j, input);
 FileOutputFormat.setOutputPath(j, output);
 System.exit(j.waitForCompletion(true)?0:1);
 }

 public static class MapForWordCount extends Mapper<LongWritable, Text, Text, IntWritable>{
  public void map(LongWritable key, Text value, Context con) throws IOException, InterruptedException
  {
   String line = value.toString();
   String[] words=line.split(" ");
   for(String word: words )
   {
    Text outputKey = new Text(word.toUpperCase().trim());
    IntWritable outputValue = new IntWritable(1);
    con.write(outputKey, outputValue);
   }
  }
 }

 public static class ReduceForWordCount extends Reducer<Text, IntWritable, Text, IntWritable>
 {
  public void reduce(Text word, Iterable<IntWritable> values, Context con) throws IOException, InterruptedException
  {
   int sum = 0;
   for(IntWritable value : values)
   {
    sum += value.get();
   }
   con.write(word, new IntWritable(sum));
  }
 }
}
EOF

# Compile and package into JAR
export HADOOP_CLASSPATH=$(hadoop classpath)
javac -classpath ${HADOOP_CLASSPATH} WordCount.java
jar cf WordCount.jar WordCount*.class

# Setup HDFS input directory and run Hadoop job
hdfs dfs -mkdir -p /input_wordCount
hdfs dfs -copyFromLocal -f word.txt /input_wordCount/
hdfs dfs -rm -r -f /output_dir
hadoop jar WordCount.jar WordCount /input_wordCount /output_dir

echo "--- Hadoop Word Count Output ---"
hdfs dfs -cat /output_dir/part-r-00000


echo "===== PART B: SPARK WORD COUNT (PYSPARK) ====="

cat << 'EOF' > wordcount_spark.py
from pyspark.sql import SparkSession

spark = SparkSession.builder \
.master("local[*]") \
.appName("word_count") \
.getOrCreate()

sc = spark.sparkContext
text_file = sc.textFile("word.txt")

counts = (text_file
.flatMap(lambda line: line.split())
.filter(lambda word: word != "")
.map(lambda word: (word, 1))
.reduceByKey(lambda x, y: x + y))

output = counts.collect()
for (word, count) in output:
    print(f"{word}: {count}")
EOF

spark-submit wordcount_spark.py

echo ""
echo "============================================"
echo " All Word Count programs executed successfully"
echo "============================================"












#Program 9

# ============================================================
# Program 9: Sales Data Analysis & Reporting using CDH / Hive
# ============================================================

set -e

echo "===== 1. CREATING SAMPLE SALES DATASET ====="
cat << 'EOF' > sales_data.csv
1,2026-01-01,North,Laptop,5,1200,6000
2,2026-01-02,South,Mouse,50,25,1250
3,2026-01-03,East,Keyboard,30,45,1350
4,2026-01-04,West,Monitor,10,300,3000
5,2026-01-05,North,Laptop,2,1200,2400
6,2026-01-06,South,Monitor,15,300,4500
EOF

echo "===== 2. UPLOADING DATA TO HDFS ====="
hdfs dfs -mkdir -p /user/root/sales_data
hdfs dfs -copyFromLocal -f sales_data.csv /user/root/sales_data/

echo "===== 3. CREATING HIVE TABLE & RUNNING QUERIES ====="
hive -e "
CREATE DATABASE IF NOT EXISTS sales_db;
USE sales_db;

CREATE TABLE IF NOT EXISTS sales_data (
 id INT,
 trans_date STRING,
 region STRING,
 product STRING,
 qty INT,
 price DOUBLE,
 sales DOUBLE
)
ROW FORMAT DELIMITED
FIELDS TERMINATED BY ','
STORED AS TEXTFILE;

LOAD DATA LOCAL INPATH 'sales_data.csv' OVERWRITE INTO TABLE sales_data;

SELECT '--- Total Sales by Region ---' as report;
SELECT region, SUM(sales) as total_revenue FROM sales_data GROUP BY region;

SELECT '--- Top Products by Quantity Sold ---' as report;
SELECT product, SUM(qty) as total_qty FROM sales_data GROUP BY product ORDER BY total_qty DESC;
"

echo ""
echo "============================================"
echo " Program 9 completed successfully"
echo "============================================"

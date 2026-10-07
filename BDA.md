# ============================================================
# Cloudera 5.x / CentOS 6.x
# MongoDB 3.2 installation & operations execution script
# ============================================================

set -e

echo "===== OS ====="
cat /etc/centos-release
uname -m

echo "===== INTERNET CHECK ====="
ping -c 3 8.8.8.8 || true
ping -c 3 google.com || true

echo "===== CENTOS REPOSITORY ====="

sudo cp /etc/yum.repos.d/CentOS-Base.repo \
    /etc/yum.repos.d/CentOS-Base.repo.backup 2>/dev/null || true

sudo bash -c 'cat > /etc/yum.repos.d/CentOS-Base.repo <<EOF
[base]
name=CentOS-6.10-Base
baseurl=http://archive.kernel.org/centos-vault/6.10/os/x86_64/
enabled=1
gpgcheck=0

[updates]
name=CentOS-6.10-Updates
baseurl=http://archive.kernel.org/centos-vault/6.10/updates/x86_64/
enabled=1
gpgcheck=0

[extras]
name=CentOS-6.10-Extras
baseurl=http://archive.kernel.org/centos-vault/6.10/extras/x86_64/
enabled=1
gpgcheck=0
EOF'

echo "===== MONGODB REPOSITORY ====="

sudo rm -f /etc/yum.repos.d/mongodb.repo

sudo bash -c 'cat > /etc/yum.repos.d/mongodb.repo <<EOF
[mongodb]
name=MongoDB Community 3.2
baseurl=http://repo.mongodb.org/yum/redhat/6/mongodb-org/3.2/x86_64/
enabled=1
gpgcheck=0
EOF'

echo "===== CLEAN YUM ====="

sudo yum clean all

echo "===== CENTOS CACHE ====="

sudo yum \
  --disablerepo="cloudera-*" \
  --disablerepo="epel" \
  --disablerepo="mongodb" \
  makecache || true

echo "===== MONGODB CACHE ====="

sudo yum \
  --disablerepo="*" \
  --enablerepo="mongodb" \
  makecache

echo "===== INSTALLING MONGODB ====="

sudo yum \
  --disablerepo="cloudera-*" \
  --disablerepo="epel" \
  install -y mongodb-org

echo "===== STARTING MONGODB ====="

sudo service mongod start

echo "===== MONGODB STATUS ====="

sudo service mongod status

echo "===== MONGODB VERSION ====="

mongo --version

echo "===== MONGODB TEST & OPERATIONS ====="

mongo college_db << 'EOF'
db.student.drop();

db.student.insertMany([
  { id: 1, name: "Alice", department: "CSE", marks: 85, age: 20 },
  { id: 2, name: "Bob", department: "ECE", marks: 75, age: 21 },
  { id: 3, name: "Charlie", department: "CSE", marks: 90, age: 22 },
  { id: 4, name: "David", department: "EEE", marks: 55, age: 20 },
  { id: 5, name: "Eve", department: "CSE", marks: 65, age: 21 },
  { id: 6, name: "Frank", department: "ECE", marks: 82, age: 22 }
]);

print("\n=== 1. COUNT DOCUMENTS ===");
print("Total documents: " + db.student.countDocuments());
print("Marks > 80 count: " + db.student.countDocuments({ marks: { $gt: 80 } }));

print("\n=== 2. SORT DOCUMENTS ===");
print("Sort by marks descending:");
printjson(db.student.find().sort({ marks: -1 }).toArray());

print("Sort by name ascending and age descending:");
printjson(db.student.find().sort({ name: 1, age: -1 }).toArray());

print("\n=== 3. LIMIT RESULTS ===");
print("Top 3 students:");
printjson(db.student.find().limit(3).toArray());

print("\n=== 4. SKIP DOCUMENTS ===");
print("Skip 2 and limit 3:");
printjson(db.student.find().skip(2).limit(3).toArray());

print("\n=== 5. AGGREGATE DOCUMENTS ===");
print("Group by Department and Count:");
printjson(db.student.aggregate([ { $group: { _id: "$department", totalStudents: { $sum: 1 } } } ]).toArray());

print("Group by Department and Average Marks:");
printjson(db.student.aggregate([ { $group: { _id: "$department", avgMarks: { $avg: "$marks" } } } ]).toArray());

print("Filter -> Group -> Sort -> Limit Pipeline:");
printjson(db.student.aggregate([
  { $match: { marks: {$gt: 60 } } },
  { $group: { _id: "$department", avgMarks: { $avg: "$marks" } } },
  { $sort: { avgMarks: -1 } },   {$limit: 3 }
]).toArray());
EOF

echo ""
echo "============================================"
echo " MongoDB installation and operations completed"
echo "============================================"

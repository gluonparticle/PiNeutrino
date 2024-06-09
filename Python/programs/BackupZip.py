import os
from zipfile import *


def backupToZip(folder):

    folder=os.path.abspath(folder)
    n=1 

    while 1:
        ZipName = os.path.basename(folder) + str(n) + '.zip'
        if not os.path.exists(ZipName):
            break 
        n+=1

    print("Creating %s  .. . . .."%ZipName)
    ZIP = ZipFile(ZipName,mode='w',compression=ZIP_DEFLATED)

    for foldername, subfolders, filenames in os.walk(folder):
        print("Adding files in %s ..........."%foldername)
        ZIP.write(foldername)

        for filename in filenames:
            ZIP.write(os.path.join(foldername,filename))
    ZIP.close()

backupToZip(r'ML-Trading')
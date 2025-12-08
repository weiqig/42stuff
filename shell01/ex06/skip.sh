#using awk to filter the output based on the current record number (NR)
ls -l | awk 'NR % 2 == 1'

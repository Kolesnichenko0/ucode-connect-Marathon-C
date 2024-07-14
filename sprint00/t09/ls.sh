ls -lhA | awk '{if (NR!=1) {print $9, $5}}'

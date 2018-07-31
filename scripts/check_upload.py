#!/usr/bin/env python3

#
# Check if a conda package with a specific version has already been uploaded to
# anaconda.org.
#

import os
import sys
import subprocess
import json


if len(sys.argv) != 3:
    sys.stderr.write("usage: check_upload.py: package_name package_path\n\n")
    sys.exit(1)

package_name = sys.argv[1]
local_tarname = os.path.basename(sys.argv[2])

cmd = ["conda", "search", "--json", "-c", "xnd/label/dev", package_name]
try:
    response = subprocess.check_output(cmd)
except:
    sys.stderr.write("check_upload.py: conda search command failed\n\n")
    sys.exit(1)

d = json.loads(response)
remote_tarname = d[package_name][0]["fn"]
sys.exit(local_tarname == remote_tarname)

#!/usr/bin/env python3

#
# Check if a conda package with a specific version has already been uploaded to
# anaconda.org.
#
# Write "true" to stdout if the package should be uploaded, "false" if
# it already exists.
#
# In case of an error, write "true": The upload should be attempted and
# fail if the package exists.
#

import os
import sys
import subprocess
import json


if len(sys.argv) != 3:
    sys.stdout.write("true\n")
    sys.exit(0)

package_name = sys.argv[1]
local_tarname = os.path.basename(sys.argv[2])

cmd = ["conda", "search", "--json", "-c", "xnd/label/dev", package_name]
try:
    response = subprocess.check_output(cmd)
except:
    sys.stdout.write("true\n")
    sys.exit(0)

try:
    d = json.loads(response)
    remote_tarname = d[package_name][0]["fn"]
except:
    sys.stdout.write("true\n")
    sys.exit(0)

sys.stdout.write("false\n" if local_tarname == remote_tarname else "true\n")

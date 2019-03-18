#
# BSD 3-Clause License
#
# Copyright (c) 2017-2018, plures
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice,
#    this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
#
# 3. Neither the name of the copyright holder nor the names of its
#    contributors may be used to endorse or promote products derived from
#    this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
# OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#


import sys
import os
import subprocess
from shutil import copy2
from glob import glob

try:
    import sphinx.cmd
    SPHINX_BUILD = "sphinx.cmd.build"
except:
    SPHINX_BUILD = "sphinx"


XND_ALL = ["ndtypes", "xnd", "gumath", "xndtools"]

LOCAL_SETUP_ARGS = """\
--single-version-externally-managed --record record.txt \
--install-base={path} --install-purelib={path} --install-platlib={path} \
--install-scripts={path} --install-data={path} --install-headers={path} \
"""

if sys.platform == "darwin": # homebrew bug
    LOCAL_SETUP_ARGS += " --prefix="

module_path = os.path.join(os.getcwd(), "python")
python_path = os.getenv('PYTHONPATH')
path = module_path + ':' + python_path if python_path else module_path
ENV = os.environ.copy()
ENV['PYTHONPATH'] = path


def err_exit():
    sys.stderr.write(
        "setup.py: usage: python3 setup.py [install, develop, test, doctest]\n\n")
    sys.exit(1)

def copy_tests():
    for lib in XND_ALL:
        if lib == "xndtools":
            pattern = os.path.join(lib, "test", "*.py")
        else:
            pattern = os.path.join(lib, "python", "*.py")
        files = glob(pattern)
        dest = os.path.join("python", "test")
        for f in files:
            copy2(f, dest)


if len(sys.argv) != 2:
    err_exit()

if sys.argv[1] == "install":
    for lib in XND_ALL:
        os.chdir(lib)
        if lib == "xndtools":
            os.system('"%s" setup.py install --single-version-externally-managed --root=/' % sys.executable)
        else:
            os.system('"%s" setup.py install' % sys.executable)
        os.chdir("..")

    copy_tests()

elif sys.argv[1] == "develop":
    installdir = os.path.join(os.getcwd(), "python")
    for lib in XND_ALL:
        os.chdir(lib)
        if lib == "xndtools":
            args = LOCAL_SETUP_ARGS.format(path=installdir)
            cmd = [sys.executable, "setup.py", "install"] + args.split()
            ret = subprocess.call(cmd, env=ENV)
            if ret != 0:
                sys.exit(ret)
        else:
            os.system('"%s" setup.py install --local=%s' % (sys.executable, installdir))
        os.chdir("..")

    copy_tests()

elif sys.argv[1] == "test":
    os.chdir("python")
    ret = subprocess.call([sys.executable, "test/test_ndtypes.py", "--long"], env=ENV)
    if ret != 0:
        sys.exit(ret)

    ret = subprocess.call([sys.executable, "test/test_xnd.py", "--long"], env=ENV)
    if ret != 0:
        sys.exit(ret)

    ret = subprocess.call([sys.executable, "test/test_gumath.py"], env=ENV)
    if ret != 0:
        sys.exit(ret)

    ret = subprocess.call([sys.executable, "test/test_xndtools.py"], env=ENV)
    sys.exit(ret)

elif sys.argv[1] == "doctest":
    module_path = os.path.join(os.getcwd(), "python")
    python_path = os.getenv('PYTHONPATH')
    path = module_path + ':' + python_path if python_path else module_path
    env = os.environ.copy()
    env['PYTHONPATH'] = path

    cmd = [sys.executable, "-m", SPHINX_BUILD,
           "-b", "doctest", "-d", "build/doctrees", ".", "build/html"]

    os.chdir("doc")
    ret = subprocess.call(cmd, env=env)
    sys.exit(ret)

else:
    err_exit()

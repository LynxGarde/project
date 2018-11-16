import subprocess
import os

def test_c():
    out = open("out.tst", "w+")
    err = open("err.tst", "w+")
    subprocess.call(["../build/42sh", "-c"], stdout=out, stderr=err)
    out.close()
    err.close()
    out = open("out.tst", "r")
    err = open("err.tst", "r")
    str_out = out.read()
    str_err = err.read()
    out.close()
    err.close()
    os.remove("out.tst")
    os.remove("err.tst")
    assert(str_out == "-c\n")
    assert(str_err == "")

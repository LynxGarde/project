import subprocess


def test_echo_hello():
    command = str.encode("echo hello")
    my_bash = subprocess.Popen(["bash"], stdout=subprocess.PIPE,
                        stderr=subprocess.PIPE, stdin=subprocess.PIPE)
    ref_bash = subprocess.Popen(["bash"], stdout=subprocess.PIPE,
                        stderr=subprocess.PIPE, stdin=subprocess.PIPE)
    my_out, my_err = my_bash.communicate(input=command)
    ref_out, ref_err = ref_bash.communicate(input=command)
    print(my_out)
    print(ref_out)
    assert(ref_out == my_out)

def test_hello():
    command = str.encode("echo hello")
    my_bash = subprocess.Popen(["bash"], stdout=subprocess.PIPE,
                        stderr=subprocess.PIPE, stdin=subprocess.PIPE)
    my_out, my_err = my_bash.communicate(input=command)
    print(my_out)
    assert(my_out == b'hello\n')

def test_bash_version():
    command = str.encode("--version")
    my_bash = subprocess.Popen(["build/42sh"], stdout=subprocess.PIPE,
                        stderr=subprocess.PIPE, stdin=subprocess.PIPE)
    my_out, my_err = my_bash.communicate(input=command)
    print(my_out)
    print(my_err)
    assert(my_out == b'Version 0.3\n')

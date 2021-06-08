The repository contains some different types of simple login systems programmed in c/c++ language. A new programmer could learn a lot by exploring this repository.

## Preview
![image](https://user-images.githubusercontent.com/50569315/121163238-6fa66400-c870-11eb-87f1-a64879e26004.png)

## Version Descriptions
You'll find these versions in the following repository.

### Version 01
It is the simplest program. It doesn't care about username and it can only check the hardcoded password `"qwerty99"`.

### Version 02
It is similar to version 01. But it can recursively check the hardcoded password `"qwerty99"`.

### Version 03
This version supports multiple users with different passwords. *(+holds previous functionality)*

### Version 04
This version can read login information from normal text file. *(+holds previous functionality)*

### Version 05
Registration system starts from here. It can write registration info into the same normal text file it reads to get the login info. This version can dynamically increase the user informations. *(+holds previous functionality)*

### Version 06
This is just an extension to the version 05. After a successful login, it shows user information on the screen. At the same time it shows some content written in `content.txt`. So, after a sucessful login someone can see the information. *(+holds previous functionality)*


### Version 07 - Encryption
This version finally uses the encryption system. While registering user info in the `database` file, it stores an randomly generated key for each user. After that, it writes the encrypted version of the given password with that key. Now, during the login process it checks the password after decrypting it. *(+holds previous functionality)*
```
    // generating random encrption key
    srand(time(0));
    int key = 1 + (rand() % 100); // random value from 1 to 100
    
    encrypt(person.password, key);

    log << person.password << ",";
    log << key << endl;
```


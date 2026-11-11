#!/usr/bin/env python3
# 1. Gather input from the user
name = input("Enter your full name: ")
# print ('"'+str(name)+'"')
phrase = input("Enter your favorite phrase : ")
print ('"'+phrase+'"')
# 2. Use string methods to clean and format the inputs
name = name.strip().lower()
# print ('"'+str(name)+'"')
phrase = phrase.replace(' ', '').upper()
print ('"'+phrase+'"')
# 3. Use string slicing to extract parts of the strings
# Get the first 3 letters of the first name
# Get the last 3 letters of the full name
username = name[:3]+name[-3:]+"_user"
# print ('"'+str(username)+'"')
# Get a slice from the middle of their favorite phrase
size=len(phrase)
if size%2==0:
    temp_password = phrase[size//2 - 2: size//2 +2]
else:
    temp_password = phrase[size//2 - 2: size//2 +3]
# 4. Combine the slices to create the outputs

# 5. Display the output to the user
print("\n--- Your New Account Details ---")
print("Username: " + username)
print("Temporary Password: " + temp_password)

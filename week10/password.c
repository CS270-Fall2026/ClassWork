#include <stdio.h>
#include <string.h>
#include <regex.h>
int check_password(const char *password) {
    regex_t regex;
    int value;
    
    // Regular expression using lookaheads to enforce all conditions simultaneously:
    // (?=.{8,})        - At least 8 characters long
    // (?=.*[A-Za-z])   - At least one letter
    // (?=.*[0-9])      - At least one number
    // (?=.*[!@#\$%\^&\*\(\)_\+-]) - At least one special character from the list
    const char *pattern = "^(?=.{8,})(?=.*[A-Za-z])(?=.*[0-9])(?=.*[!@#\\$%\\^&\\*\\(\\)_\\+-])";

    // Compile POSIX Extended Regular Expression (REG_EXTENDED)
    value = regcomp(&regex, pattern, REG_EXTENDED | REG_NOSUB);
    if (value != 0) {
        printf("Regex compilation failed.\n");
        return 0;
    }

    // Execute regex match
    value = regexec(&regex, password, 0, NULL, 0);
    regfree(&regex);

    // If value is 0, a match was found
    return (value == 0);
}
int main()
{
    char password[100];
    while(1)
    {
        printf("Your passwerd must be:\n");
        printf("   * At least 8 characters\n");
        printf("   * Have at least one letter\n");
        printf("   * Have at least one number\n");
        printf("   * Have at least one special character (!@#$%%^&*()_+-\n");
        printf("Enter passwerd: ");
        scanf("%s",password);

    }
}
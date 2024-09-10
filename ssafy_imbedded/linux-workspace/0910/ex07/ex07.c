#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toUpperString(char *temp, char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        temp[i] = toupper(str[i]);
    }   
    temp[strlen(str)] = '\0';
}

int check_end(char* str) {
  char temp[100];
  toUpperString(temp, str);
  if(strncmp(temp, "BYE\0", 4) == 0 || strncmp(temp, "EXIT\0", 5) == 0) {
    
    return 1;
  }

  return 0;
}

int main() {
  
    while(1) {
      char str[100];
      printf("SAFFY_ECHOBOT >> ");
      scanf("%s", str);
      if(check_end(str)) {
        break;
      }   
      printf("%s\n", str);
    }   

    return 0;
}
~           
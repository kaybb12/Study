int main() {
    char input[MAX_INPUT];

    while (1) {
        // 프롬프트 출력
        printf("SSAFY > ");
        fgets(input, sizeof(input), stdin);

        // 개행 문자 제거
        input[strcspn(input, "\n")] = 0;

        // 히스토리에 추가
        add_to_history(input);

        // 명령어 처리
        if (strcmp(input, "date") == 0) {
            system("date");
        } else if (strcmp(input, "uptime") == 0) {
            system("uptime");
        } else if (strcmp(input, "ls") == 0) {
            system("ls -al");
        } else if (strcmp(input, "log") == 0) {
            system("dmesg");
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else if (strcmp(input, "history") == 0) {
            print_history();
        } else if (strncmp(input, "!", 1) == 0) {
            // ! 번호로 명령어 실행
            int index = atoi(input + 1) - 1;
            if (index >= 0 && index < history_count) {
                printf("Executing: %s\n", history[index]);
                add_to_history(history[index]);
                system(history[index]);
            } else {
                printf("ERROR: Invalid history number\n");
            }
        } else if (strcmp(input, "hclear") == 0) {
            clear_history();
        } else {
            printf("ERROR\n");
        }
    }

    // 프로그램 종료 시 히스토리 메모리 해제
    clear_history();
    return 0;
}

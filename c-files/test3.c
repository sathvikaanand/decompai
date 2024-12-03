#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void log_system_resources() {
    FILE *log_file = fopen("system_resources.log", "a");
    if (log_file == NULL) {
        perror("Could not open log file");
        return;
    }

    time_t now;
    struct tm *tm_info;
    time(&now);
    tm_info = localtime(&now);

    // Log the current time
    fprintf(log_file, "System Resources at %02d:%02d:%02d - ", tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec);

    // Get and log CPU usage (using the 'top' command)
    FILE *fp = popen("top -bn1 | grep 'Cpu(s)'", "r");
    if (fp) {
        char buffer[256];
        fgets(buffer, sizeof(buffer), fp);
        fprintf(log_file, "CPU: %s", buffer);
        fclose(fp);
    }

    // Get and log memory usage (using the 'free' command)
    fp = popen("free -m", "r");
    if (fp) {
        char buffer[256];
        fgets(buffer, sizeof(buffer), fp);  // Skip the first line
        fgets(buffer, sizeof(buffer), fp);
        fprintf(log_file, "Memory: %s", buffer);
        fclose(fp);
    }

    // Log load average (using the 'uptime' command)
    fp = popen("uptime", "r");
    if (fp) {
        char buffer[256];
        fgets(buffer, sizeof(buffer), fp);
        fprintf(log_file, "Load Average: %s", buffer);
        fclose(fp);
    }

    fclose(log_file);
    printf("System resources logged.\n");
}

int main() {
    while (1) {
        log_system_resources();
        sleep(3600);  // Log every hour
    }
    return 0;
}

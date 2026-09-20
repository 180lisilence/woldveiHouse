/* ---------- 全局通信路径（DllMain时初始化） ---------- */
static char g_comm_dir[MAX_PATH] = {0};
static char g_cmd_file[MAX_PATH] = {0};
static char g_result_file[MAX_PATH] = {0};

/* ---------- 检查并执行命令文件 ---------- */
static void check_command_file() {
    FILE *f = fopen(g_cmd_file, "rb");
    if (!f) return;

    /* 读取命令 */
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);
    if (size <= 0 || size > 100000) {
        fclose(f);
        DeleteFileA(g_cmd_file);
        return;
    }

    char *cmd = (char *)malloc(size + 1);
    fread(cmd, 1, size, f);
    cmd[size] = 0;
    fclose(f);
    DeleteFileA(g_cmd_file);

    /* 执行Lua */
    char result_buf[8192];
    memset(result_buf, 0, sizeof(result_buf));
    int ok = execute_lua(cmd, result_buf, sizeof(result_buf) - 1);
    free(cmd);

    /* 写结果 */
    FILE *rf = fopen(g_result_file, "wb");
    if (rf) {
        fprintf(rf, "%s", result_buf);
        fclose(rf);
    }
}

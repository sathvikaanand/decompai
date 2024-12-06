
void _timeout_handler(void)

{
  _puts("\n\nTimeout expired!");
                    /* WARNING: Subroutine does not return */
  _exit(1);
}


void _decode(char *param_1,long param_2,ulong param_3)

{
  void *pvVar1;
  size_t sVar2;
  uint uVar3;
  long lVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  ulong uVar8;
  
  if (*param_1 == '\0' || param_3 == 0) {
    uVar8 = 0;
  }
  else {
    uVar8 = 0;
    uVar3 = 0;
    lVar4 = 0;
    iVar5 = 0;
    uVar6 = 0;
    do {
      pvVar1 = _memchr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/",
                       (int)param_1[lVar4],0x41);
      uVar7 = uVar6;
      if (pvVar1 == (void *)0x0) {
LAB_100003598:
        sVar2 = _strlen(param_1);
        uVar8 = (ulong)iVar5;
        if (sVar2 <= lVar4 + 1U) break;
      }
      else {
        uVar3 = (int)pvVar1 - 0x3f4fU | uVar3 << 6;
        uVar7 = uVar6 - 2;
        if (1 < (int)uVar6) {
          iVar5 = iVar5 + 1;
          *(char *)(param_2 + uVar8) = (char)((int)uVar3 >> (uVar7 & 0x1f));
          goto LAB_100003598;
        }
        uVar7 = uVar6 + 6;
        sVar2 = _strlen(param_1);
        uVar8 = (ulong)iVar5;
        if (sVar2 <= lVar4 + 1U) break;
      }
      lVar4 = lVar4 + 1;
      uVar6 = uVar7;
    } while (uVar8 < param_3);
  }
  *(undefined *)(param_2 + uVar8) = 0;
  return;
}


void _list_files(void)

{
  long lVar1;
  long lVar2;
  char *pcVar3;
  
  lVar1 = _opendir("./files");
  if (lVar1 == 0) {
    _perror("Could not open directory");
    return;
  }
  pcVar3 = "Files:";
  do {
    _puts(pcVar3);
    do {
      lVar2 = _readdir(lVar1);
      if (lVar2 == 0) {
        _closedir(lVar1);
        return;
      }
      pcVar3 = (char *)(lVar2 + 0x15);
    } while (*pcVar3 == '.');
  } while( true );
}


void _print_file(char *param_1)

{
  int iVar1;
  FILE *pFVar2;
  char *pcVar3;
  char acStack_138 [256];
  long local_38;
  
  local_38 = *(long *)PTR____stack_chk_guard_100004010;
  pFVar2 = _fopen(param_1,"r");
  if (pFVar2 == (FILE *)0x0) {
    iVar1 = 0;
    if (*(long *)PTR____stack_chk_guard_100004010 == local_38) {
      _perror("Error opening file");
      return;
    }
  }
  else {
    pcVar3 = _fgets(acStack_138,0x100,pFVar2);
    while (pcVar3 != (char *)0x0) {
      _printf("%s");
      pcVar3 = _fgets(acStack_138,0x100,pFVar2);
    }
    iVar1 = _fclose(pFVar2);
    if (*(long *)PTR____stack_chk_guard_100004010 == local_38) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(iVar1);
}


undefined8 entry(void)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  size_t sVar5;
  void *pvVar6;
  FILE *pFVar7;
  char *extraout_x1;
  char *pcVar8;
  undefined8 uVar9;
  ulong uVar10;
  ulong uVar11;
  uint uVar12;
  int local_1574;
  char acStack_1570 [4096];
  char acStack_570 [512];
  char local_370 [512];
  char acStack_170 [256];
  long local_70;
  
  iVar2 = (*(code *)PTR____chkstk_darwin_100004000)();
  puVar1 = PTR__optarg_1000040b0;
  pcVar8 = (char *)0x0;
  local_70 = *(long *)PTR____stack_chk_guard_100004010;
  while( true ) {
    while (iVar3 = _getopt(iVar2,extraout_x1,"t:w:d"), 0x73 < iVar3) {
      if (iVar3 == 0x74) {
        _timeout = _atoi(*(char **)puVar1);
      }
      else {
        if (iVar3 != 0x77) goto LAB_100003ba4;
        pcVar8 = _strdup(*(char **)puVar1);
      }
    }
    if (iVar3 != 100) break;
    _debug = 1;
  }
  if (iVar3 == -1) {
    if (_timeout != 0) {
      _signal(0xe);
      _alarm(_timeout);
    }
    if (pcVar8 != (char *)0x0) {
      _chdir(pcVar8);
    }
    _getcwd(acStack_1570,0x1000);
    if (_debug != 0) {
      _getuid();
      _printf("Running service %s in %s as user %d...\n");
    }
    goto LAB_1000038d8;
  }
LAB_100003ba4:
  uVar4 = _fprintf(*(FILE **)PTR____stderrp_100004018,"Usage: %s -t <timeout> -w <workdir> [-d]\n");
  uVar11 = (ulong)uVar4;
  uVar9 = 1;
  goto LAB_100003c14;
LAB_1000038d8:
  while( true ) {
    while( true ) {
      _puts("Select an option:");
      _puts("1. List files");
      _puts("2. Read a file");
      _puts("3. Exit");
      _printf("Enter your choice: ");
      _fflush(*(FILE **)PTR____stdoutp_100004020);
      iVar2 = _scanf("%d");
      if (iVar2 == 1) break;
      _fwrite("Invalid input\n",0xe,1,*(FILE **)PTR____stderrp_100004018);
      do {
        iVar2 = _getchar();
      } while (iVar2 != 10);
    }
    if (local_1574 != 1) break;
    _list_files();
  }
  if (local_1574 == 2) {
    _printf("Enter the filename: ");
    _fflush(*(FILE **)PTR____stdoutp_100004020);
    _scanf("%s");
    pcVar8 = _strstr(local_370 + 0x100,"..");
    if (pcVar8 != (char *)0x0) {
      uVar9 = 1;
      uVar11 = _fwrite("Unsafe pattern detected!\n",0x19,1,*(FILE **)PTR____stderrp_100004018);
      goto LAB_100003c14;
    }
    if (local_370[0x100] == -0x70) {
      if (local_370[0x101] == '\0') {
        uVar11 = 0;
      }
      else {
        sVar5 = _strlen(local_370 + 0x101);
        uVar11 = 0;
        uVar4 = 0;
        uVar12 = 0;
        uVar10 = 1;
        do {
          pvVar6 = _memchr("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/",
                           (int)local_370[uVar10 + 0x100],0x41);
          if (pvVar6 != (void *)0x0) {
            uVar4 = (int)pvVar6 - 0x3f4fU | uVar4 << 6;
            if ((int)uVar12 < 2) {
              uVar12 = uVar12 + 6;
            }
            else {
              local_370[uVar11] = (char)((int)uVar4 >> (uVar12 - 2 & 0x1f));
              uVar11 = uVar11 + 1;
              uVar12 = uVar12 - 2;
            }
          }
        } while ((uVar10 < sVar5) && (uVar10 = uVar10 + 1, uVar11 < 0x100));
      }
      local_370[uVar11] = '\0';
      if (_debug != 0) {
        _printf("Decoded filename: %s\n");
      }
    }
    else {
      _strncpy(local_370,local_370 + 0x100,0xff);
      local_370[0xff] = 0;
    }
    _snprintf(acStack_570,0x200,"./files/%s");
    _printf("Opening file %s\n");
    pFVar7 = _fopen(acStack_570,"r");
    if (pFVar7 == (FILE *)0x0) {
      _perror("Error opening file");
    }
    else {
      pcVar8 = _fgets(acStack_170,0x100,pFVar7);
      while (pcVar8 != (char *)0x0) {
        _printf("%s");
        pcVar8 = _fgets(acStack_170,0x100,pFVar7);
      }
      _fclose(pFVar7);
    }
    _fflush(*(FILE **)PTR____stdoutp_100004020);
    goto LAB_1000038d8;
  }
  if (local_1574 != 3) {
    _puts("Invalid choice. Try again.");
    _fflush(*(FILE **)PTR____stdoutp_100004020);
    goto LAB_1000038d8;
  }
  _puts("Exiting...");
  uVar4 = _fflush(*(FILE **)PTR____stdoutp_100004020);
  uVar11 = (ulong)uVar4;
  uVar9 = 0;
LAB_100003c14:
  if (*(long *)PTR____stack_chk_guard_100004010 == local_70) {
    return uVar9;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(uVar11);
}


void ___stack_chk_fail(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100003c60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR____stack_chk_fail_100004008)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint _alarm(uint param_1)

{
  uint uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003c6c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)PTR__alarm_100004028)(param_1);
  return uVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _atoi(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003c78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__atoi_100004030)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _chdir(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003c84. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__chdir_100004038)((int)param_1);
  return iVar1;
}


void _closedir(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100003c90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__closedir_100004040)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _exit(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003c9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__exit_100004048)(param_1);
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fclose(FILE *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003ca8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fclose_100004050)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fflush(FILE *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003cb4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fflush_100004058)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _fgets(char *param_1,int param_2,FILE *param_3)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003cc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__fgets_100004060)(param_1,param_2);
  return pcVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * _fopen(char *param_1,char *param_2)

{
  FILE *pFVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003ccc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pFVar1 = (FILE *)(*(code *)PTR__fopen_100004068)();
  return pFVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fprintf(FILE *param_1,char *param_2,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003cd8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fprintf_100004070)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t _fwrite(void *param_1,size_t param_2,size_t param_3,FILE *param_4)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003ce4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = (*(code *)PTR__fwrite_100004078)();
  return sVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _getchar(void)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003cf0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__getchar_100004080)();
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _getcwd(char *param_1,size_t param_2)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003cfc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__getcwd_100004088)();
  return pcVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _getopt(int param_1,char *param_2,char *param_3)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003d08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__getopt_100004090)(param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uid_t _getuid(void)

{
  uid_t uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003d14. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)PTR__getuid_100004098)();
  return uVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * _memchr(void *param_1,int param_2,size_t param_3)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003d20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = (void *)(*(code *)PTR__memchr_1000040a0)(param_1,param_2);
  return pvVar1;
}


void _opendir(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100003d2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__opendir_1000040a8)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _perror(char *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003d38. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__perror_1000040b8)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _printf(char *param_1,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003d44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__printf_1000040c0)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _puts(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003d50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__puts_1000040c8)((int)param_1);
  return iVar1;
}


void _readdir(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100003d5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__readdir_1000040d0)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _scanf(char *param_1,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003d68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__scanf_1000040d8)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _signal(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003d74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__signal_1000040e0)(param_1);
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _snprintf(char *param_1,size_t param_2,char *param_3,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003d80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__snprintf_1000040e8)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _strdup(char *param_1)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003d8c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__strdup_1000040f0)();
  return pcVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t _strlen(char *param_1)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003d98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = (*(code *)PTR__strlen_1000040f8)();
  return sVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _strncpy(char *param_1,char *param_2,size_t param_3)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003da4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__strncpy_100004100)();
  return pcVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _strstr(char *param_1,char *param_2)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003db0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__strstr_100004108)();
  return pcVar1;
}


/* WARNING: Control flow encountered bad instruction data */

void ___chkstk_darwin(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



void FUN_100003358(void)

{
  _printf("\n\nTimeout expired!\n");
                    /* WARNING: Subroutine does not return */
  _exit(1);
}


undefined4 entry(void)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  char *pcVar4;
  size_t sVar5;
  char *extraout_x1;
  char *local_12c0;
  wordexp_t wStack_12b0;
  FILE *local_1298;
  char *local_1290;
  char *local_1288;
  char *local_1280;
  ulong local_1278;
  char acStack_126d [4];
  undefined local_1269;
  char *local_1268;
  int local_1260;
  undefined4 local_125c;
  char acStack_1258 [4096];
  char local_258 [8];
  char local_250;
  char acStack_249 [16];
  char acStack_239 [512];
  char acStack_39 [17];
  long local_28;
  
  local_1260 = (*(code *)PTR____chkstk_darwin_100004000)();
  puVar2 = PTR____stdoutp_100004028;
  puVar1 = PTR____stdinp_100004020;
  local_28 = *(long *)PTR____stack_chk_guard_100004010;
  local_125c = 0;
  local_258[0] = s_idXXXXXX_100003d9f[0];
  local_258[1] = s_idXXXXXX_100003d9f[1];
  local_258[2] = s_idXXXXXX_100003d9f[2];
  local_258[3] = s_idXXXXXX_100003d9f[3];
  local_258[4] = s_idXXXXXX_100003d9f[4];
  local_258[5] = s_idXXXXXX_100003d9f[5];
  local_258[6] = s_idXXXXXX_100003d9f[6];
  local_258[7] = s_idXXXXXX_100003d9f[7];
  local_250 = s_idXXXXXX_100003d9f[8];
  local_1278 = 0;
  local_12c0 = (char *)0x0;
  local_1268 = extraout_x1;
  while (iVar3 = _getopt(local_1260,local_1268,"t:w:d"), iVar3 != -1) {
    if (iVar3 == 100) {
      DAT_10000800c = 1;
    }
    else if (iVar3 == 0x74) {
      DAT_100008008 = _atoi(*(char **)PTR__optarg_1000040c0);
    }
    else {
      if (iVar3 != 0x77) {
        _fprintf(*(FILE **)PTR____stderrp_100004018,"Usage: %s -t <timeout> -w <workdir> [-d]\n");
        local_125c = 1;
        goto LAB_100003bd4;
      }
      local_12c0 = _strdup(*(char **)PTR__optarg_1000040c0);
    }
  }
  if (DAT_100008008 != 0) {
    _signal(0xe);
    _alarm(DAT_100008008);
  }
  if (local_12c0 != (char *)0x0) {
    _chdir(local_12c0);
  }
  _getcwd(acStack_1258,0x1000);
  if (DAT_10000800c != 0) {
    _getuid();
    _printf("Running service %s in %s as user %d...\n");
  }
  _umask(0);
  local_1280 = _mkdtemp(local_258);
  if (local_1280 == (char *)0x0) {
    _perror("mkdtemp");
    local_125c = 1;
  }
  else {
    iVar3 = _chdir(local_1280);
    if (iVar3 == 0) {
      _printf("Your service ID is %s\n");
      _fflush(*(FILE **)puVar2);
LAB_100003638:
      _printf("Command (load/store/quit): ");
      _fflush(*(FILE **)puVar2);
      pcVar4 = _fgets(acStack_249 + 1,0x10,*(FILE **)puVar1);
      if (pcVar4 != (char *)0x0) {
        sVar5 = _strlen(acStack_249 + 1);
        if ((acStack_249 + 1)[sVar5 - 1] == '\n') {
          sVar5 = _strlen(acStack_249 + 1);
          (acStack_249 + 1)[sVar5 - 1] = '\0';
        }
        iVar3 = _strcmp(acStack_249 + 1,"load");
        if (iVar3 == 0) {
          _printf("Please enter a variable: ");
          _fflush(*(FILE **)puVar2);
          pcVar4 = _fgets(acStack_39 + 1,0x10,*(FILE **)puVar1);
          if (pcVar4 == (char *)0x0) {
            _perror("fgets");
            local_125c = 1;
            goto LAB_100003bd4;
          }
          sVar5 = _strlen(acStack_39 + 1);
          if ((acStack_39 + 1)[sVar5 - 1] == '\n') {
            sVar5 = _strlen(acStack_39 + 1);
            (acStack_39 + 1)[sVar5 - 1] = '\0';
          }
          _printf("Please enter a value: ");
          _fflush(*(FILE **)puVar2);
          pcVar4 = _fgets(acStack_239 + 1,0x200,*(FILE **)puVar1);
          if (pcVar4 == (char *)0x0) {
            _perror("fgets");
            local_125c = 1;
            goto LAB_100003bd4;
          }
          sVar5 = _strlen(acStack_239 + 1);
          if ((acStack_239 + 1)[sVar5 - 1] == '\n') {
            sVar5 = _strlen(acStack_239 + 1);
            (acStack_239 + 1)[sVar5 - 1] = '\0';
          }
          _setenv(acStack_39 + 1,acStack_239 + 1,1);
          goto LAB_100003638;
        }
        iVar3 = _strcmp(acStack_249 + 1,"store");
        if (iVar3 == 0) {
          _printf("Please enter a variable: ");
          _fflush(*(FILE **)puVar2);
          pcVar4 = _fgets(acStack_39 + 1,0x10,*(FILE **)puVar1);
          if (pcVar4 == (char *)0x0) {
            _perror("fgets");
            local_125c = 1;
            goto LAB_100003bd4;
          }
          sVar5 = _strlen(acStack_39 + 1);
          if ((acStack_39 + 1)[sVar5 - 1] == '\n') {
            sVar5 = _strlen(acStack_39 + 1);
            (acStack_39 + 1)[sVar5 - 1] = '\0';
          }
          local_1288 = _getenv(acStack_39 + 1);
          if (local_1288 == (char *)0x0) {
            _printf("Non-existent variable!\n");
            _fflush(*(FILE **)puVar2);
            goto LAB_100003638;
          }
          _wordexp("~/permissions",&wStack_12b0,0);
          local_1290 = *wStack_12b0.we_wordv;
          _printf("Opening permission file %s\n");
          local_1298 = _fopen(local_1290,"r");
          if (local_1298 == (FILE *)0x0) {
            _printf("Cannot find the permission file\n");
            _perror("fopen");
            _fflush(*(FILE **)puVar2);
            _printf("Creating permission file %s\n");
            local_1298 = _fopen(local_1290,"w+");
            if (local_1298 == (FILE *)0x0) {
              _perror("fopen");
              _printf("Cannot create the file permissions spec\n");
              _fflush(*(FILE **)puVar2);
              goto LAB_100003638;
            }
            _fwrite("0600",4,1,local_1298);
            _rewind(local_1298);
          }
          _fread(acStack_126d,1,4,local_1298);
          local_1269 = 0;
          local_1278 = _strtoul(acStack_126d,(char **)0x0,8);
          local_1298 = _fopen(acStack_39 + 1,"w+");
          pcVar4 = local_1288;
          sVar5 = _strlen(local_1288);
          _fwrite(pcVar4,sVar5,1,local_1298);
          _fclose(local_1298);
          iVar3 = _chmod(acStack_39 + 1,(mode_t)local_1278);
          _printf("chmod %lx res %d\n");
          if (iVar3 != 0) {
            _perror("chmod");
          }
          _printf("Variable value saved!\n");
          _fflush(*(FILE **)puVar2);
        }
        else {
          iVar3 = _strcmp(acStack_249 + 1,"quit");
          if (iVar3 == 0) {
            _printf("Currently saved values:\n");
            _execlp("ls","ls");
            local_125c = 0;
            goto LAB_100003bd4;
          }
          _printf("Unknown command!\n");
        }
        goto LAB_100003638;
      }
      _perror("fgets");
      local_125c = 1;
    }
    else {
      _perror("chdir");
      local_125c = 1;
    }
  }
LAB_100003bd4:
  if (*(long *)PTR____stack_chk_guard_100004010 == local_28) {
    return local_125c;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}


void ___stack_chk_fail(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100003c20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR____stack_chk_fail_100004008)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint _alarm(uint param_1)

{
  uint uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003c2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)PTR__alarm_100004030)(param_1);
  return uVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _atoi(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003c38. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__atoi_100004038)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _chdir(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003c44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__chdir_100004040)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _chmod(char *param_1,mode_t param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003c50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__chmod_100004048)((int)param_1,param_2);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _execlp(char *param_1,char *param_2,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003c5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__execlp_100004050)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _exit(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003c68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__exit_100004058)(param_1);
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fclose(FILE *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003c74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fclose_100004060)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fflush(FILE *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003c80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fflush_100004068)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _fgets(char *param_1,int param_2,FILE *param_3)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003c8c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__fgets_100004070)(param_1,param_2);
  return pcVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * _fopen(char *param_1,char *param_2)

{
  FILE *pFVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003c98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pFVar1 = (FILE *)(*(code *)PTR__fopen_100004078)();
  return pFVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fprintf(FILE *param_1,char *param_2,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003ca4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fprintf_100004080)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t _fread(void *param_1,size_t param_2,size_t param_3,FILE *param_4)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003cb0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = (*(code *)PTR__fread_100004088)();
  return sVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t _fwrite(void *param_1,size_t param_2,size_t param_3,FILE *param_4)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003cbc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = (*(code *)PTR__fwrite_100004090)();
  return sVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _getcwd(char *param_1,size_t param_2)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003cc8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__getcwd_100004098)();
  return pcVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _getenv(char *param_1)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003cd4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__getenv_1000040a0)();
  return pcVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _getopt(int param_1,char *param_2,char *param_3)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003ce0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__getopt_1000040a8)(param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uid_t _getuid(void)

{
  uid_t uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003cec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)PTR__getuid_1000040b0)();
  return uVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _mkdtemp(char *param_1)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003cf8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__mkdtemp_1000040b8)();
  return pcVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _perror(char *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003d04. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__perror_1000040c8)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _printf(char *param_1,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003d10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__printf_1000040d0)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _rewind(FILE *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003d1c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__rewind_1000040d8)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _setenv(char *param_1,char *param_2,int param_3)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003d28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__setenv_1000040e0)((int)param_1,param_2,param_3);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _signal(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003d34. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__signal_1000040e8)(param_1);
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _strcmp(char *param_1,char *param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003d40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__strcmp_1000040f0)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _strdup(char *param_1)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003d4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__strdup_1000040f8)();
  return pcVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t _strlen(char *param_1)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003d58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = (*(code *)PTR__strlen_100004100)();
  return sVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ulong _strtoul(char *param_1,char **param_2,int param_3)

{
  ulong uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003d64. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)PTR__strtoul_100004108)(param_1,param_2,param_3);
  return uVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

mode_t _umask(mode_t param_1)

{
  mode_t mVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003d70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  mVar1 = (*(code *)PTR__umask_100004110)(param_1);
  return mVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _wordexp(char *param_1,wordexp_t *param_2,int param_3)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003d7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__wordexp_100004118)((int)param_1,param_2,param_3);
  return iVar1;
}


/* WARNING: Control flow encountered bad instruction data */

void ___chkstk_darwin(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



void _timeout_handler(void)

{
  _puts("\n\nTimeout expired!");
                    /* WARNING: Subroutine does not return */
  _exit(1);
}


void entry(void)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  size_t sVar5;
  FILE *pFVar6;
  ulong uVar7;
  undefined8 uVar8;
  char *extraout_x1;
  char *pcVar9;
  char *pcVar10;
  wordexp_t wStack_12c8;
  char acStack_12ad [4];
  undefined local_12a9;
  FILE *local_12a8;
  char acStack_12a0 [4096];
  char local_2a0 [8];
  undefined local_298;
  char cStack_291;
  int local_290;
  short local_28c;
  char acStack_281 [512];
  char acStack_81 [17];
  long local_70;
  
  iVar3 = (*(code *)PTR____chkstk_darwin_100004000)();
  puVar1 = PTR__optarg_1000040c0;
  pcVar9 = (char *)0x0;
  local_70 = *(long *)PTR____stack_chk_guard_100004010;
  local_2a0[0] = s_idXXXXXX_100003d87[0];
  local_2a0[1] = s_idXXXXXX_100003d87[1];
  local_2a0[2] = s_idXXXXXX_100003d87[2];
  local_2a0[3] = s_idXXXXXX_100003d87[3];
  local_2a0[4] = s_idXXXXXX_100003d87[4];
  local_2a0[5] = s_idXXXXXX_100003d87[5];
  local_2a0[6] = s_idXXXXXX_100003d87[6];
  local_2a0[7] = s_idXXXXXX_100003d87[7];
  local_298 = 0;
  while( true ) {
    while (iVar4 = _getopt(iVar3,extraout_x1,"t:w:d"), 0x73 < iVar4) {
      if (iVar4 == 0x74) {
        _timeout = _atoi(*(char **)puVar1);
      }
      else {
        if (iVar4 != 0x77) goto LAB_100003a88;
        pcVar9 = _strdup(*(char **)puVar1);
      }
    }
    if (iVar4 != 100) break;
    _debug = 1;
  }
  if (iVar4 == -1) {
    if (_timeout != 0) {
      _signal(0xe);
      _alarm(_timeout);
    }
    if (pcVar9 != (char *)0x0) {
      _chdir(pcVar9);
    }
    _getcwd(acStack_12a0,0x1000);
    if (_debug != 0) {
      _getuid();
      _printf("Running service %s in %s as user %d...\n");
    }
    _umask(0);
    pcVar9 = _mkdtemp(local_2a0);
    if (pcVar9 == (char *)0x0) {
      pcVar9 = "mkdtemp";
      goto LAB_100003ae4;
    }
    iVar3 = _chdir(pcVar9);
    if (iVar3 != 0) {
      pcVar9 = "chdir";
      goto LAB_100003ae4;
    }
    _printf("Your service ID is %s\n");
    puVar2 = PTR____stdoutp_100004028;
    _fflush(*(FILE **)PTR____stdoutp_100004028);
    _printf("Command (load/store/quit): ");
    _fflush(*(FILE **)puVar2);
    puVar1 = PTR____stdinp_100004020;
    pcVar9 = _fgets((char *)&local_290,0x10,*(FILE **)PTR____stdinp_100004020);
    goto joined_r0x000100003768;
  }
LAB_100003a88:
  _fprintf(*(FILE **)PTR____stderrp_100004018,"Usage: %s -t <timeout> -w <workdir> [-d]\n");
LAB_100003ae8:
  uVar8 = 1;
LAB_100003aec:
  if (*(long *)PTR____stack_chk_guard_100004010 == local_70) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(uVar8);
joined_r0x000100003768:
  if (pcVar9 == (char *)0x0) goto LAB_100003adc;
  sVar5 = _strlen((char *)&local_290);
  if ((&cStack_291)[sVar5] == '\n') {
    (&cStack_291)[sVar5] = '\0';
  }
  if (local_290 == 0x64616f6c && (char)local_28c == '\0') {
    _printf("Please enter a variable: ");
    _fflush(*(FILE **)puVar2);
    pcVar9 = _fgets(acStack_81 + 1,0x10,*(FILE **)puVar1);
    if (pcVar9 == (char *)0x0) goto LAB_100003adc;
    sVar5 = _strlen(acStack_81 + 1);
    if (acStack_81[sVar5] == '\n') {
      acStack_81[sVar5] = '\0';
    }
    _printf("Please enter a value: ");
    _fflush(*(FILE **)puVar2);
    pcVar9 = _fgets(acStack_281 + 1,0x200,*(FILE **)puVar1);
    if (pcVar9 == (char *)0x0) goto LAB_100003adc;
    sVar5 = _strlen(acStack_281 + 1);
    if (acStack_281[sVar5] == '\n') {
      acStack_281[sVar5] = '\0';
    }
    _setenv(acStack_81 + 1,acStack_281 + 1,1);
  }
  else if (local_290 == 0x726f7473 && local_28c == 0x65) {
    _printf("Please enter a variable: ");
    _fflush(*(FILE **)puVar2);
    pcVar9 = _fgets(acStack_81 + 1,0x10,*(FILE **)puVar1);
    if (pcVar9 == (char *)0x0) goto LAB_100003adc;
    sVar5 = _strlen(acStack_81 + 1);
    if (acStack_81[sVar5] == '\n') {
      acStack_81[sVar5] = '\0';
    }
    pcVar9 = _getenv(acStack_81 + 1);
    if (pcVar9 == (char *)0x0) {
      _puts("Non-existent variable!");
      _fflush(*(FILE **)puVar2);
    }
    else {
      _wordexp("~/permissions",&wStack_12c8,0);
      pcVar10 = *wStack_12c8.we_wordv;
      _printf("Opening permission file %s\n");
      pFVar6 = _fopen(pcVar10,"r");
      if ((pFVar6 != (FILE *)0x0) ||
         (uVar7 = _main_cold_1(pcVar10,&local_12a8), pFVar6 = local_12a8, (uVar7 & 1) == 0)) {
        _fread(acStack_12ad,1,4,pFVar6);
        local_12a9 = 0;
        uVar7 = _strtoul(acStack_12ad,(char **)0x0,8);
        pFVar6 = _fopen(acStack_81 + 1,"w+");
        sVar5 = _strlen(pcVar9);
        _fwrite(pcVar9,sVar5,1,pFVar6);
        _fclose(pFVar6);
        iVar3 = _chmod(acStack_81 + 1,(mode_t)uVar7);
        _printf("chmod %lx res %d\n");
        if (iVar3 != 0) {
          _perror("chmod");
        }
        _puts("Variable value saved!");
        _fflush(*(FILE **)puVar2);
      }
    }
  }
  else {
    if (local_290 == 0x74697571 && (char)local_28c == '\0') {
      _puts("Currently saved values:");
      _execlp("ls","ls");
      uVar8 = 0;
      goto LAB_100003aec;
    }
    _puts("Unknown command!");
  }
  _printf("Command (load/store/quit): ");
  _fflush(*(FILE **)puVar2);
  pcVar9 = _fgets((char *)&local_290,0x10,*(FILE **)puVar1);
  goto joined_r0x000100003768;
LAB_100003adc:
  pcVar9 = "fgets";
LAB_100003ae4:
  _perror(pcVar9);
  goto LAB_100003ae8;
}


bool _main_cold_1(char *param_1,undefined8 *param_2)

{
  undefined *puVar1;
  FILE *pFVar2;
  
  _puts("Cannot find the permission file");
  _perror("fopen");
  puVar1 = PTR____stdoutp_100004028;
  _fflush(*(FILE **)PTR____stdoutp_100004028);
  _printf("Creating permission file %s\n");
  pFVar2 = _fopen(param_1,"w+");
  *param_2 = pFVar2;
  if (pFVar2 == (FILE *)0x0) {
    _perror("fopen");
    _puts("Cannot create the file permissions spec");
    _fflush(*(FILE **)puVar1);
  }
  else {
    _fwrite("0600",4,1,pFVar2);
    _rewind(pFVar2);
  }
  return pFVar2 == (FILE *)0x0;
}


void ___stack_chk_fail(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100003c1c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR____stack_chk_fail_100004008)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint _alarm(uint param_1)

{
  uint uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003c28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)PTR__alarm_100004030)(param_1);
  return uVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _atoi(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003c34. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__atoi_100004038)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _chdir(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003c40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__chdir_100004040)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _chmod(char *param_1,mode_t param_2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003c4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__chmod_100004048)((int)param_1,param_2);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _execlp(char *param_1,char *param_2,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003c58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__execlp_100004050)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _exit(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003c64. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__exit_100004058)(param_1);
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fclose(FILE *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003c70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fclose_100004060)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fflush(FILE *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003c7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fflush_100004068)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _fgets(char *param_1,int param_2,FILE *param_3)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003c88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__fgets_100004070)(param_1,param_2);
  return pcVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

FILE * _fopen(char *param_1,char *param_2)

{
  FILE *pFVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003c94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pFVar1 = (FILE *)(*(code *)PTR__fopen_100004078)();
  return pFVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fprintf(FILE *param_1,char *param_2,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003ca0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fprintf_100004080)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t _fread(void *param_1,size_t param_2,size_t param_3,FILE *param_4)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003cac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = (*(code *)PTR__fread_100004088)();
  return sVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t _fwrite(void *param_1,size_t param_2,size_t param_3,FILE *param_4)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003cb8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = (*(code *)PTR__fwrite_100004090)();
  return sVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _getcwd(char *param_1,size_t param_2)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003cc4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__getcwd_100004098)();
  return pcVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _getenv(char *param_1)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003cd0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__getenv_1000040a0)();
  return pcVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _getopt(int param_1,char *param_2,char *param_3)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003cdc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__getopt_1000040a8)(param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uid_t _getuid(void)

{
  uid_t uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003ce8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)PTR__getuid_1000040b0)();
  return uVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _mkdtemp(char *param_1)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003cf4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__mkdtemp_1000040b8)();
  return pcVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _perror(char *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003d00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__perror_1000040c8)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _printf(char *param_1,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003d0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__printf_1000040d0)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _puts(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003d18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__puts_1000040d8)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _rewind(FILE *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003d24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__rewind_1000040e0)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _setenv(char *param_1,char *param_2,int param_3)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003d30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__setenv_1000040e8)((int)param_1,param_2,param_3);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _signal(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003d3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__signal_1000040f0)(param_1);
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _strdup(char *param_1)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003d48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__strdup_1000040f8)();
  return pcVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t _strlen(char *param_1)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003d54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = (*(code *)PTR__strlen_100004100)();
  return sVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ulong _strtoul(char *param_1,char **param_2,int param_3)

{
  ulong uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003d60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)PTR__strtoul_100004108)(param_1,param_2,param_3);
  return uVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

mode_t _umask(mode_t param_1)

{
  mode_t mVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003d6c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  mVar1 = (*(code *)PTR__umask_100004110)(param_1);
  return mVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _wordexp(char *param_1,wordexp_t *param_2,int param_3)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003d78. Too many branches */
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


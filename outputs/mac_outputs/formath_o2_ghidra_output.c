
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
  char *pcVar3;
  size_t sVar4;
  undefined8 uVar5;
  char acStack_4b8 [1023];
  char local_b9 [64];
  char cStack_79;
  int local_78;
  char local_74;
  long local_38;
  
  local_38 = *(long *)PTR____stack_chk_guard_100004008;
  if (_timeout != 0) {
    _signal(0xe);
    _alarm(_timeout);
  }
  _printf("Execution id: %p\n");
  _printf("Please provide a mathematical function: ");
  puVar2 = PTR____stdoutp_100004018;
  _fflush(*(FILE **)PTR____stdoutp_100004018);
  puVar1 = PTR____stdinp_100004010;
  pcVar3 = _fgets((char *)&local_78,0x40,*(FILE **)PTR____stdinp_100004010);
  if (pcVar3 != (char *)0x0) {
    sVar4 = _strlen((char *)&local_78);
    if ((&cStack_79)[sVar4] == '\n') {
      (&cStack_79)[sVar4] = '\0';
    }
    _printf("Please provide a parameter: ");
    _fflush(*(FILE **)puVar2);
    pcVar3 = _fgets(local_b9 + 1,0x40,*(FILE **)puVar1);
    if (pcVar3 != (char *)0x0) {
      sVar4 = _strlen(local_b9 + 1);
      if (local_b9[sVar4] == '\n') {
        local_b9[sVar4] = '\0';
      }
      _atof(local_b9 + 1);
      if (local_78 != 0x736261) {
        if (local_78 == 0x686e6973 && local_74 == '\0') {
          _sinh();
        }
        else if (local_78 == 0x68736f63 && local_74 == '\0') {
          _cosh();
        }
        else {
          if (local_78 != 0x686e6174 || local_74 != '\0') {
            _printf("Unknown function %s!\n");
            uVar5 = 1;
            goto LAB_100003df0;
          }
          _tanh();
        }
      }
      _snprintf(acStack_4b8,0x3ff,"The application of %s to %s returned %f\n");
      local_b9[0] = '\0';
      _printf(acStack_4b8);
      uVar5 = 0;
      goto LAB_100003df0;
    }
  }
  _perror("fgets");
  uVar5 = 1;
LAB_100003df0:
  if (*(long *)PTR____stack_chk_guard_100004008 == local_38) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail(uVar5);
}


void ___stack_chk_fail(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100003e28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR____stack_chk_fail_100004000)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint _alarm(uint param_1)

{
  uint uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e34. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)PTR__alarm_100004020)(param_1);
  return uVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

double _atof(char *param_1)

{
  double dVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  dVar1 = (double)(*(code *)PTR__atof_100004028)();
  return dVar1;
}


void _cosh(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100003e4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__cosh_100004030)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _exit(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003e58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__exit_100004038)(param_1);
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fflush(FILE *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e64. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fflush_100004040)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _fgets(char *param_1,int param_2,FILE *param_3)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e70. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__fgets_100004048)(param_1,param_2);
  return pcVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _perror(char *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003e7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__perror_100004050)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _printf(char *param_1,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__printf_100004058)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _puts(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__puts_100004060)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _signal(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003ea0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__signal_100004068)(param_1);
  return;
}


void _sinh(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100003eac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__sinh_100004070)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _snprintf(char *param_1,size_t param_2,char *param_3,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003eb8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__snprintf_100004078)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t _strlen(char *param_1)

{
  size_t sVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003ec4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  sVar1 = (*(code *)PTR__strlen_100004080)();
  return sVar1;
}


void _tanh(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100003ed0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__tanh_100004088)();
  return;
}


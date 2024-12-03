
int _init(EVP_PKEY_CTX *ctx)

{
  undefined *puVar1;
  
  puVar1 = PTR___gmon_start___00103fd8;
  if (PTR___gmon_start___00103fd8 != (undefined *)0x0) {
    puVar1 = (undefined *)(*(code *)PTR___gmon_start___00103fd8)();
  }
  return (int)puVar1;
}


void FUN_00101020(void)

{
  (*(code *)PTR_00103ff8)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_printf_00104000)();
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

double tanh(double __x)

{
  double dVar1;
  
  dVar1 = (double)(*(code *)PTR_tanh_00104008)();
  return dVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_strlen_00104010)();
  return sVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void perror(char *__s)

{
  (*(code *)PTR_perror_00104018)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

double sinh(double __x)

{
  double dVar1;
  
  dVar1 = (double)(*(code *)PTR_sinh_00104020)();
  return dVar1;
}


void __stack_chk_fail(void)

{
  (*(code *)PTR___stack_chk_fail_00104028)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fflush(FILE *__stream)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fflush_00104030)();
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__sighandler_t signal(int __sig,__sighandler_t __handler)

{
  __sighandler_t p_Var1;
  
  p_Var1 = (__sighandler_t)(*(code *)PTR_signal_00104038)();
  return p_Var1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void exit(int __status)

{
  (*(code *)PTR_exit_00104040)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

double atof(char *__nptr)

{
  double dVar1;
  
  dVar1 = (double)(*(code *)PTR_atof_00104048)();
  return dVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

double cosh(double __x)

{
  double dVar1;
  
  dVar1 = (double)(*(code *)PTR_cosh_00104050)();
  return dVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_strcmp_00104058)();
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int puts(char *__s)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_puts_00104060)();
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * fgets(char *__s,int __n,FILE *__stream)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_fgets_00104068)();
  return pcVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_snprintf_00104070)();
  return iVar1;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint alarm(uint __seconds)

{
  uint uVar1;
  
  uVar1 = (*_DAT_00104078)();
  return uVar1;
}


void processEntry _start(undefined8 param_1,undefined8 param_2)

{
  undefined auStack_8 [8];
  
  (*(code *)PTR___libc_start_main_00103fc8)(main,param_2,&stack0x00000008,0,0,param_1,auStack_8);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


/* WARNING: Removing unreachable block (ram,0x00101173) */
/* WARNING: Removing unreachable block (ram,0x0010117f) */

void FUN_00101160(void)

{
  return;
}


/* WARNING: Removing unreachable block (ram,0x001011b4) */
/* WARNING: Removing unreachable block (ram,0x001011c0) */

void FUN_00101190(void)

{
  return;
}


void _FINI_0(void)

{
  if (DAT_001040b8 == '\0') {
    if (PTR___cxa_finalize_00103fc0 != (undefined *)0x0) {
      (*(code *)PTR___cxa_finalize_00103fc0)(__dso_handle);
    }
    FUN_00101160();
    DAT_001040b8 = 1;
    return;
  }
  return;
}


void _INIT_0(void)

{
  FUN_00101190();
  return;
}


/* timeout_handler(int) */

void timeout_handler(int param_1)

{
  puts("\n\nTimeout expired!");
                    /* WARNING: Subroutine does not return */
  exit(1);
}


undefined8 main(void)

{
  int iVar1;
  char *pcVar2;
  undefined8 uVar3;
  size_t sVar4;
  long in_FS_OFFSET;
  double local_4a8;
  undefined8 local_4a0;
  char local_498 [63];
  char acStack_459 [65];
  char local_418 [1023];
  undefined local_19;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  if (timeout != 0) {
    signal(0xe,timeout_handler);
    alarm(timeout);
  }
  printf("Execution id: %p\n",local_418);
  printf("Please provide a mathematical function: ");
  fflush(stdout);
  pcVar2 = fgets(local_498,0x40,stdin);
  if (pcVar2 == (char *)0x0) {
    perror("fgets");
    uVar3 = 1;
  }
  else {
    sVar4 = strlen(local_498);
    if (local_498[sVar4 - 1] == '\n') {
      sVar4 = strlen(local_498);
      local_498[sVar4 - 1] = '\0';
    }
    printf("Please provide a parameter: ");
    fflush(stdout);
    pcVar2 = fgets(acStack_459 + 1,0x40,stdin);
    if (pcVar2 == (char *)0x0) {
      perror("fgets");
      uVar3 = 1;
    }
    else {
      sVar4 = strlen(acStack_459 + 1);
      if (acStack_459[sVar4] == '\n') {
        sVar4 = strlen(acStack_459 + 1);
        acStack_459[sVar4] = '\0';
      }
      local_4a0 = atof(acStack_459 + 1);
      iVar1 = strcmp(local_498,"abs");
      if (iVar1 == 0) {
        local_4a8 = (double)std::abs(local_4a0);
      }
      else {
        iVar1 = strcmp(local_498,"sinh");
        if (iVar1 == 0) {
          local_4a8 = sinh(local_4a0);
        }
        else {
          iVar1 = strcmp(local_498,"cosh");
          if (iVar1 == 0) {
            local_4a8 = cosh(local_4a0);
          }
          else {
            iVar1 = strcmp(local_498,"tanh");
            if (iVar1 != 0) {
              printf("Unknown function %s!\n",local_498);
              uVar3 = 1;
              goto LAB_00101592;
            }
            local_4a8 = tanh(local_4a0);
          }
        }
      }
      snprintf(local_418,0x3ff,"The application of %s to %s returned %f\n",local_4a8,local_498,
               acStack_459 + 1);
      local_19 = 0;
      printf(local_418);
      uVar3 = 0;
    }
  }
LAB_00101592:
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* std::abs(double) */

ulong std::abs(double param_1)

{
  return (ulong)param_1 & DAT_001020f0;
}


void _fini(void)

{
  return;
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int printf(char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* printf@GLIBC_2.2.5 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

double tanh(double __x)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* tanh@GLIBC_2.2.5 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void __cxa_finalize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __cxa_finalize@GLIBC_2.2.5 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* strlen@GLIBC_2.2.5 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void __libc_start_main(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __libc_start_main@GLIBC_2.34 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void perror(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* perror@GLIBC_2.2.5 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

double sinh(double __x)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* sinh@GLIBC_2.2.5 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __stack_chk_fail@GLIBC_2.4 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int fflush(FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* fflush@GLIBC_2.2.5 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__sighandler_t signal(int __sig,__sighandler_t __handler)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* signal@GLIBC_2.2.5 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void exit(int __status)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* exit@GLIBC_2.2.5 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

double atof(char *__nptr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* atof@GLIBC_2.2.5 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

double cosh(double __x)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* cosh@GLIBC_2.2.5 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* strcmp@GLIBC_2.2.5 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int puts(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* puts@GLIBC_2.2.5 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * fgets(char *__s,int __n,FILE *__stream)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* fgets@GLIBC_2.2.5 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* snprintf@GLIBC_2.2.5 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void _ITM_deregisterTMCloneTable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void __gmon_start__(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint alarm(uint __seconds)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* alarm@GLIBC_2.2.5 */
  halt_baddata();
}


/* WARNING: Control flow encountered bad instruction data */

void _ITM_registerTMCloneTable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


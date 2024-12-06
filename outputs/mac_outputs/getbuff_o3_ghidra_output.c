
void _timeout_handler(void)

{
  _puts("\n\nTimeout expired!");
                    /* WARNING: Subroutine does not return */
  _exit(1);
}


void entry(void)

{
  undefined auVar1 [16];
  undefined auVar2 [16];
  undefined auVar3 [16];
  undefined4 uVar4;
  undefined6 uVar5;
  undefined4 uVar6;
  undefined6 uVar7;
  undefined4 uVar8;
  undefined6 uVar9;
  uint uVar10;
  undefined *puVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  undefined8 uVar15;
  char *extraout_x1;
  ulong uVar16;
  ulong uVar17;
  ulong uVar18;
  long lVar19;
  undefined8 *puVar20;
  char *pcVar21;
  byte bVar22;
  byte bVar23;
  byte bVar24;
  byte bVar25;
  byte bVar26;
  byte bVar27;
  byte bVar28;
  byte bVar29;
  byte bVar30;
  byte bVar31;
  byte bVar32;
  byte bVar33;
  byte bVar34;
  byte bVar35;
  byte bVar36;
  byte bVar37;
  byte bVar38;
  byte bVar42;
  byte bVar43;
  byte bVar44;
  byte bVar45;
  byte bVar46;
  byte bVar47;
  byte bVar48;
  byte bVar49;
  byte bVar50;
  byte bVar51;
  byte bVar52;
  byte bVar53;
  byte bVar54;
  byte bVar55;
  byte bVar56;
  undefined auVar39 [16];
  undefined auVar40 [16];
  undefined auVar41 [16];
  byte bVar57;
  byte bVar58;
  byte bVar59;
  byte bVar60;
  byte bVar61;
  byte bVar62;
  byte bVar63;
  byte bVar64;
  byte bVar65;
  byte bVar67;
  byte bVar68;
  byte bVar69;
  byte bVar70;
  byte bVar71;
  byte bVar72;
  undefined8 uVar66;
  byte bVar73;
  byte bVar74;
  byte bVar76;
  byte bVar77;
  byte bVar78;
  byte bVar79;
  byte bVar80;
  byte bVar81;
  undefined8 uVar75;
  byte bVar82;
  byte bVar83;
  byte bVar85;
  byte bVar86;
  byte bVar87;
  byte bVar88;
  byte bVar89;
  byte bVar90;
  undefined8 uVar84;
  byte bVar91;
  byte bVar92;
  byte bVar94;
  byte bVar95;
  byte bVar96;
  byte bVar97;
  byte bVar98;
  byte bVar99;
  undefined8 uVar93;
  byte bVar100;
  byte bVar101;
  byte bVar103;
  byte bVar104;
  byte bVar105;
  byte bVar106;
  byte bVar107;
  byte bVar108;
  undefined8 uVar102;
  byte bVar109;
  byte bVar110;
  byte bVar112;
  byte bVar113;
  byte bVar114;
  byte bVar115;
  byte bVar116;
  byte bVar117;
  undefined8 uVar111;
  byte bVar118;
  byte bVar119;
  byte bVar121;
  byte bVar122;
  byte bVar123;
  byte bVar124;
  byte bVar125;
  byte bVar126;
  undefined8 uVar120;
  byte bVar127;
  byte bVar128;
  byte bVar130;
  byte bVar131;
  byte bVar132;
  byte bVar133;
  byte bVar134;
  byte bVar135;
  undefined8 uVar129;
  byte bVar136;
  byte bVar137;
  byte bVar139;
  byte bVar140;
  byte bVar141;
  byte bVar142;
  byte bVar143;
  byte bVar144;
  undefined8 uVar138;
  byte bVar145;
  byte bVar146;
  byte bVar148;
  byte bVar149;
  byte bVar150;
  byte bVar151;
  byte bVar152;
  byte bVar153;
  undefined8 uVar147;
  byte bVar154;
  byte bVar155;
  byte bVar157;
  byte bVar158;
  byte bVar159;
  byte bVar160;
  byte bVar161;
  byte bVar162;
  undefined8 uVar156;
  byte bVar163;
  undefined8 uVar164;
  undefined8 uVar165;
  undefined8 uVar166;
  undefined8 uVar167;
  char acStack_1468 [4096];
  char local_468 [8];
  undefined8 auStack_460 [127];
  long local_68;
  
  iVar12 = (*(code *)PTR____chkstk_darwin_100004000)();
  puVar11 = PTR__optarg_100004078;
  pcVar21 = (char *)0x0;
  local_68 = *(long *)PTR____stack_chk_guard_100004010;
  while( true ) {
    while (iVar13 = _getopt(iVar12,extraout_x1,"t:w:d"), 0x73 < iVar13) {
      if (iVar13 == 0x74) {
        _timeout = _atoi(*(char **)puVar11);
      }
      else {
        if (iVar13 != 0x77) goto LAB_100003b8c;
        pcVar21 = _strdup(*(char **)puVar11);
      }
    }
    if (iVar13 != 100) break;
    _debug = 1;
  }
  if (iVar13 == -1) {
    if (_timeout != 0) {
      _signal(0xe);
      _alarm(_timeout);
    }
    if (pcVar21 != (char *)0x0) {
      _chdir(pcVar21);
    }
    _getcwd(acStack_1468,0x1000);
    if (_debug != 0) {
      _getuid();
      _printf("Running service %s in %s as user %d...\n");
    }
    _printf(
           "Welcome to the checksum verifier service!\n    Your service ticket id is: %p\n    Please provide the data to verify: "
           );
    puVar11 = PTR____stdoutp_100004020;
    _fflush(*(FILE **)PTR____stdoutp_100004020);
    _i = 0;
    uVar14 = _getchar();
    _c = (undefined)uVar14;
    uVar10 = _i;
    while ((uVar14 & 0xff) != 10) {
      local_468[(int)uVar10] = (char)uVar14;
      _i = uVar10 + 1;
      local_468[(long)(int)uVar10 + 1] = '\0';
      uVar14 = _getchar();
      _c = (undefined)uVar14;
      uVar10 = _i;
    }
    _i = uVar10;
    _printf("Received a buffer of length %d\n");
    _fflush(*(FILE **)puVar11);
    _checksum = 0;
    uVar16 = (ulong)_i;
    if ((int)_i < 1) {
      _j = 0;
    }
    else {
      if (_i < 8) {
        uVar17 = 0;
        _checksum = 0;
LAB_100003d08:
        lVar19 = uVar16 - uVar17;
        pcVar21 = local_468 + uVar17;
        do {
          _checksum = _checksum ^ (int)*pcVar21;
          lVar19 = lVar19 + -1;
          pcVar21 = pcVar21 + 1;
        } while (lVar19 != 0);
      }
      else if (_i < 0x20) {
        _checksum = 0;
        uVar18 = 0;
LAB_100003ca4:
        uVar17 = uVar16 & 0xfffffff8;
        bVar22 = 0;
        bVar23 = 0;
        bVar24 = 0;
        bVar25 = 0;
        bVar26 = 0;
        bVar27 = 0;
        bVar28 = 0;
        bVar29 = 0;
        bVar30 = 0;
        bVar31 = 0;
        bVar32 = 0;
        bVar33 = 0;
        bVar34 = 0;
        bVar35 = 0;
        bVar36 = 0;
        bVar37 = 0;
        auVar39._4_12_ = SUB1612(ZEXT816(0),4);
        auVar39._0_4_ = _checksum;
        lVar19 = uVar18 - uVar17;
        pcVar21 = local_468 + uVar18;
        do {
          uVar15 = *(undefined8 *)pcVar21;
          bVar38 = (byte)uVar15;
          bVar42 = (byte)((ulong)uVar15 >> 8);
          bVar43 = (byte)((ulong)uVar15 >> 0x10);
          bVar44 = (byte)((ulong)uVar15 >> 0x18);
          bVar45 = (byte)((ulong)uVar15 >> 0x20);
          bVar46 = (byte)((ulong)uVar15 >> 0x28);
          bVar47 = (byte)((ulong)uVar15 >> 0x30);
          bVar48 = (byte)((ulong)uVar15 >> 0x38);
          bVar22 = bVar22 ^ bVar45;
          bVar23 = bVar23 ^ (char)bVar45 >> 7;
          bVar24 = bVar24 ^ (byte)((short)(char)bVar45 >> 0xf);
          bVar25 = bVar25 ^ (byte)((short)(char)bVar45 >> 0xf);
          bVar26 = bVar26 ^ bVar46;
          bVar27 = bVar27 ^ (char)bVar46 >> 7;
          bVar28 = bVar28 ^ (byte)((short)(char)bVar46 >> 0xf);
          bVar29 = bVar29 ^ (byte)((short)(char)bVar46 >> 0xf);
          bVar30 = bVar30 ^ bVar47;
          bVar31 = bVar31 ^ (char)bVar47 >> 7;
          bVar32 = bVar32 ^ (byte)((short)(char)bVar47 >> 0xf);
          bVar33 = bVar33 ^ (byte)((short)(char)bVar47 >> 0xf);
          bVar34 = bVar34 ^ bVar48;
          bVar35 = bVar35 ^ (char)bVar48 >> 7;
          bVar36 = bVar36 ^ (byte)((short)(char)bVar48 >> 0xf);
          bVar37 = bVar37 ^ (byte)((short)(char)bVar48 >> 0xf);
          auVar40[0] = auVar39[0] ^ bVar38;
          auVar40[1] = auVar39[1] ^ (char)bVar38 >> 7;
          auVar40[2] = auVar39[2] ^ (byte)((short)(char)bVar38 >> 0xf);
          auVar40[3] = auVar39[3] ^ (byte)((short)(char)bVar38 >> 0xf);
          auVar40[4] = auVar39[4] ^ bVar42;
          auVar40[5] = auVar39[5] ^ (char)bVar42 >> 7;
          auVar40[6] = auVar39[6] ^ (byte)((short)(char)bVar42 >> 0xf);
          auVar40[7] = auVar39[7] ^ (byte)((short)(char)bVar42 >> 0xf);
          auVar40[8] = auVar39[8] ^ bVar43;
          auVar40[9] = auVar39[9] ^ (char)bVar43 >> 7;
          auVar40[10] = auVar39[10] ^ (byte)((short)(char)bVar43 >> 0xf);
          auVar40[0xb] = auVar39[0xb] ^ (byte)((short)(char)bVar43 >> 0xf);
          auVar40[0xc] = auVar39[0xc] ^ bVar44;
          auVar40[0xd] = auVar39[0xd] ^ (char)bVar44 >> 7;
          auVar40[0xe] = auVar39[0xe] ^ (byte)((short)(char)bVar44 >> 0xf);
          auVar40[0xf] = auVar39[0xf] ^ (byte)((short)(char)bVar44 >> 0xf);
          lVar19 = lVar19 + 8;
          pcVar21 = pcVar21 + 8;
          auVar39 = auVar40;
        } while (lVar19 != 0);
        bVar22 = auVar40[0] ^ bVar22;
        bVar23 = auVar40[1] ^ bVar23;
        bVar24 = auVar40[2] ^ bVar24;
        bVar25 = auVar40[3] ^ bVar25;
        bVar26 = auVar40[4] ^ bVar26;
        bVar27 = auVar40[5] ^ bVar27;
        bVar28 = auVar40[6] ^ bVar28;
        bVar29 = auVar40[7] ^ bVar29;
        auVar1[1] = bVar23;
        auVar1[0] = bVar22;
        auVar1[2] = bVar24;
        auVar1[3] = bVar25;
        auVar1[4] = bVar26;
        auVar1[5] = bVar27;
        auVar1[6] = bVar28;
        auVar1[7] = bVar29;
        auVar1[8] = auVar40[8] ^ bVar30;
        auVar1[9] = auVar40[9] ^ bVar31;
        auVar1[10] = auVar40[10] ^ bVar32;
        auVar1[0xb] = auVar40[0xb] ^ bVar33;
        auVar1[0xc] = auVar40[0xc] ^ bVar34;
        auVar1[0xd] = auVar40[0xd] ^ bVar35;
        auVar1[0xe] = auVar40[0xe] ^ bVar36;
        auVar1[0xf] = auVar40[0xf] ^ bVar37;
        auVar2[1] = bVar23;
        auVar2[0] = bVar22;
        auVar2[2] = bVar24;
        auVar2[3] = bVar25;
        auVar2[4] = bVar26;
        auVar2[5] = bVar27;
        auVar2[6] = bVar28;
        auVar2[7] = bVar29;
        auVar2[8] = auVar40[8] ^ bVar30;
        auVar2[9] = auVar40[9] ^ bVar31;
        auVar2[10] = auVar40[10] ^ bVar32;
        auVar2[0xb] = auVar40[0xb] ^ bVar33;
        auVar2[0xc] = auVar40[0xc] ^ bVar34;
        auVar2[0xd] = auVar40[0xd] ^ bVar35;
        auVar2[0xe] = auVar40[0xe] ^ bVar36;
        auVar2[0xf] = auVar40[0xf] ^ bVar37;
        auVar41 = NEON_ext(auVar1,auVar2,8,1);
        _checksum = CONCAT13(bVar25 ^ auVar41[3],
                             CONCAT12(bVar24 ^ auVar41[2],
                                      CONCAT11(bVar23 ^ auVar41[1],bVar22 ^ auVar41[0]))) ^
                    CONCAT13(bVar29 ^ auVar41[7],
                             CONCAT12(bVar28 ^ auVar41[6],
                                      CONCAT11(bVar27 ^ auVar41[5],bVar26 ^ auVar41[4])));
        if (uVar17 != uVar16) goto LAB_100003d08;
      }
      else {
        bVar22 = 0;
        bVar23 = 0;
        bVar24 = 0;
        bVar25 = 0;
        bVar26 = 0;
        bVar27 = 0;
        bVar28 = 0;
        bVar29 = 0;
        bVar30 = 0;
        bVar31 = 0;
        bVar32 = 0;
        bVar33 = 0;
        bVar34 = 0;
        bVar35 = 0;
        bVar36 = 0;
        bVar37 = 0;
        uVar17 = uVar16 & 0xffffffe0;
        bVar38 = 0;
        bVar42 = 0;
        bVar43 = 0;
        bVar44 = 0;
        bVar45 = 0;
        bVar46 = 0;
        bVar47 = 0;
        bVar48 = 0;
        bVar49 = 0;
        bVar50 = 0;
        bVar51 = 0;
        bVar52 = 0;
        bVar53 = 0;
        bVar54 = 0;
        bVar55 = 0;
        bVar56 = 0;
        puVar20 = auStack_460 + 1;
        uVar75 = 0;
        uVar84 = 0;
        uVar15 = 0;
        uVar66 = 0;
        uVar111 = 0;
        uVar120 = 0;
        uVar93 = 0;
        uVar102 = 0;
        uVar129 = 0;
        uVar138 = 0;
        uVar147 = 0;
        uVar156 = 0;
        uVar18 = uVar17;
        do {
          uVar165 = puVar20[-1];
          uVar164 = puVar20[-2];
          uVar167 = puVar20[1];
          uVar166 = *puVar20;
          bVar92 = (byte)uVar164;
          bVar95 = (byte)((ulong)uVar164 >> 8);
          bVar98 = (byte)((ulong)uVar164 >> 0x10);
          bVar101 = (byte)((ulong)uVar164 >> 0x18);
          bVar104 = (byte)((ulong)uVar164 >> 0x20);
          bVar108 = (byte)((ulong)uVar164 >> 0x28);
          bVar114 = (byte)((ulong)uVar164 >> 0x30);
          bVar118 = (byte)((ulong)uVar164 >> 0x38);
          uVar4 = CONCAT13((char)bVar95 >> 7,CONCAT12(bVar95,(short)(char)bVar92));
          uVar5 = CONCAT15((char)bVar98 >> 7,CONCAT14(bVar98,uVar4));
          uVar6 = CONCAT13((char)bVar108 >> 7,CONCAT12(bVar108,(short)(char)bVar104));
          uVar7 = CONCAT15((char)bVar114 >> 7,CONCAT14(bVar114,uVar6));
          bVar123 = (byte)((short)(char)bVar104 >> 0xf);
          bVar124 = (byte)((int)uVar6 >> 0x1f);
          bVar125 = (byte)((int6)uVar7 >> 0x2f);
          bVar127 = (byte)((long)CONCAT17((char)bVar118 >> 7,CONCAT16(bVar118,uVar7)) >> 0x3f);
          bVar78 = (byte)uVar165;
          bVar82 = (byte)((ulong)uVar165 >> 8);
          bVar87 = (byte)((ulong)uVar165 >> 0x10);
          bVar91 = (byte)((ulong)uVar165 >> 0x18);
          bVar60 = (byte)((ulong)uVar165 >> 0x20);
          bVar64 = (byte)((ulong)uVar165 >> 0x28);
          bVar69 = (byte)((ulong)uVar165 >> 0x30);
          bVar73 = (byte)((ulong)uVar165 >> 0x38);
          bVar113 = (byte)uVar166;
          bVar116 = (byte)((ulong)uVar166 >> 8);
          bVar121 = (byte)((ulong)uVar166 >> 0x10);
          bVar126 = (byte)((ulong)uVar166 >> 0x18);
          bVar106 = (byte)((ulong)uVar166 >> 0x20);
          bVar110 = (byte)((ulong)uVar166 >> 0x28);
          bVar115 = (byte)((ulong)uVar166 >> 0x30);
          bVar119 = (byte)((ulong)uVar166 >> 0x38);
          uVar6 = CONCAT13((char)bVar116 >> 7,CONCAT12(bVar116,(short)(char)bVar113));
          uVar7 = CONCAT15((char)bVar121 >> 7,CONCAT14(bVar121,uVar6));
          uVar8 = CONCAT13((char)bVar110 >> 7,CONCAT12(bVar110,(short)(char)bVar106));
          uVar9 = CONCAT15((char)bVar115 >> 7,CONCAT14(bVar115,uVar8));
          bVar96 = (byte)((short)(char)bVar106 >> 0xf);
          bVar100 = (byte)((int)uVar8 >> 0x1f);
          bVar105 = (byte)((int6)uVar9 >> 0x2f);
          bVar109 = (byte)((long)CONCAT17((char)bVar119 >> 7,CONCAT16(bVar119,uVar9)) >> 0x3f);
          bVar94 = (byte)uVar167;
          bVar97 = (byte)((ulong)uVar167 >> 8);
          bVar99 = (byte)((ulong)uVar167 >> 0x10);
          bVar103 = (byte)((ulong)uVar167 >> 0x18);
          bVar107 = (byte)((ulong)uVar167 >> 0x20);
          bVar112 = (byte)((ulong)uVar167 >> 0x28);
          bVar117 = (byte)((ulong)uVar167 >> 0x30);
          bVar122 = (byte)((ulong)uVar167 >> 0x38);
          bVar57 = (byte)uVar15 ^ bVar60;
          bVar58 = (byte)((ulong)uVar15 >> 8) ^ (char)bVar60 >> 7;
          bVar59 = (byte)((ulong)uVar15 >> 0x10) ^ (byte)((short)(char)bVar60 >> 0xf);
          bVar60 = (byte)((ulong)uVar15 >> 0x18) ^ (byte)((short)(char)bVar60 >> 0xf);
          bVar61 = (byte)((ulong)uVar15 >> 0x20) ^ bVar64;
          bVar62 = (byte)((ulong)uVar15 >> 0x28) ^ (char)bVar64 >> 7;
          bVar63 = (byte)((ulong)uVar15 >> 0x30) ^ (byte)((short)(char)bVar64 >> 0xf);
          bVar64 = (byte)((ulong)uVar15 >> 0x38) ^ (byte)((short)(char)bVar64 >> 0xf);
          uVar15 = CONCAT17(bVar64,CONCAT16(bVar63,CONCAT15(bVar62,CONCAT14(bVar61,CONCAT13(bVar60,
                                                  CONCAT12(bVar59,CONCAT11(bVar58,bVar57)))))));
          bVar65 = (byte)uVar66 ^ bVar69;
          bVar67 = (byte)((ulong)uVar66 >> 8) ^ (char)bVar69 >> 7;
          bVar68 = (byte)((ulong)uVar66 >> 0x10) ^ (byte)((short)(char)bVar69 >> 0xf);
          bVar69 = (byte)((ulong)uVar66 >> 0x18) ^ (byte)((short)(char)bVar69 >> 0xf);
          bVar70 = (byte)((ulong)uVar66 >> 0x20) ^ bVar73;
          bVar71 = (byte)((ulong)uVar66 >> 0x28) ^ (char)bVar73 >> 7;
          bVar72 = (byte)((ulong)uVar66 >> 0x30) ^ (byte)((short)(char)bVar73 >> 0xf);
          bVar73 = (byte)((ulong)uVar66 >> 0x38) ^ (byte)((short)(char)bVar73 >> 0xf);
          uVar66 = CONCAT17(bVar73,CONCAT16(bVar72,CONCAT15(bVar71,CONCAT14(bVar70,CONCAT13(bVar69,
                                                  CONCAT12(bVar68,CONCAT11(bVar67,bVar65)))))));
          bVar74 = (byte)uVar75 ^ bVar78;
          bVar76 = (byte)((ulong)uVar75 >> 8) ^ (char)bVar78 >> 7;
          bVar77 = (byte)((ulong)uVar75 >> 0x10) ^ (byte)((short)(char)bVar78 >> 0xf);
          bVar78 = (byte)((ulong)uVar75 >> 0x18) ^ (byte)((short)(char)bVar78 >> 0xf);
          bVar79 = (byte)((ulong)uVar75 >> 0x20) ^ bVar82;
          bVar80 = (byte)((ulong)uVar75 >> 0x28) ^ (char)bVar82 >> 7;
          bVar81 = (byte)((ulong)uVar75 >> 0x30) ^ (byte)((short)(char)bVar82 >> 0xf);
          bVar82 = (byte)((ulong)uVar75 >> 0x38) ^ (byte)((short)(char)bVar82 >> 0xf);
          uVar75 = CONCAT17(bVar82,CONCAT16(bVar81,CONCAT15(bVar80,CONCAT14(bVar79,CONCAT13(bVar78,
                                                  CONCAT12(bVar77,CONCAT11(bVar76,bVar74)))))));
          bVar83 = (byte)uVar84 ^ bVar87;
          bVar85 = (byte)((ulong)uVar84 >> 8) ^ (char)bVar87 >> 7;
          bVar86 = (byte)((ulong)uVar84 >> 0x10) ^ (byte)((short)(char)bVar87 >> 0xf);
          bVar87 = (byte)((ulong)uVar84 >> 0x18) ^ (byte)((short)(char)bVar87 >> 0xf);
          bVar88 = (byte)((ulong)uVar84 >> 0x20) ^ bVar91;
          bVar89 = (byte)((ulong)uVar84 >> 0x28) ^ (char)bVar91 >> 7;
          bVar90 = (byte)((ulong)uVar84 >> 0x30) ^ (byte)((short)(char)bVar91 >> 0xf);
          bVar91 = (byte)((ulong)uVar84 >> 0x38) ^ (byte)((short)(char)bVar91 >> 0xf);
          uVar84 = CONCAT17(bVar91,CONCAT16(bVar90,CONCAT15(bVar89,CONCAT14(bVar88,CONCAT13(bVar87,
                                                  CONCAT12(bVar86,CONCAT11(bVar85,bVar83)))))));
          bVar38 = bVar38 ^ bVar104;
          bVar42 = bVar42 ^ (char)bVar104 >> 7;
          bVar43 = bVar43 ^ bVar123;
          bVar44 = bVar44 ^ bVar123;
          bVar45 = bVar45 ^ bVar108;
          bVar46 = bVar46 ^ (char)bVar108 >> 7;
          bVar47 = bVar47 ^ bVar124;
          bVar48 = bVar48 ^ bVar124;
          bVar49 = bVar49 ^ bVar114;
          bVar50 = bVar50 ^ (char)bVar114 >> 7;
          bVar51 = bVar51 ^ bVar125;
          bVar52 = bVar52 ^ bVar125;
          bVar53 = bVar53 ^ bVar118;
          bVar54 = bVar54 ^ (char)bVar118 >> 7;
          bVar55 = bVar55 ^ bVar127;
          bVar56 = bVar56 ^ bVar127;
          bVar22 = bVar22 ^ bVar92;
          bVar23 = bVar23 ^ (char)bVar92 >> 7;
          bVar92 = (byte)((short)(char)bVar92 >> 0xf);
          bVar24 = bVar24 ^ bVar92;
          bVar25 = bVar25 ^ bVar92;
          bVar26 = bVar26 ^ bVar95;
          bVar27 = bVar27 ^ (char)bVar95 >> 7;
          bVar92 = (byte)((int)uVar4 >> 0x1f);
          bVar28 = bVar28 ^ bVar92;
          bVar29 = bVar29 ^ bVar92;
          bVar30 = bVar30 ^ bVar98;
          bVar31 = bVar31 ^ (char)bVar98 >> 7;
          bVar92 = (byte)((int6)uVar5 >> 0x2f);
          bVar32 = bVar32 ^ bVar92;
          bVar33 = bVar33 ^ bVar92;
          bVar34 = bVar34 ^ bVar101;
          bVar35 = bVar35 ^ (char)bVar101 >> 7;
          bVar92 = (byte)((long)CONCAT17((char)bVar101 >> 7,CONCAT16(bVar101,uVar5)) >> 0x3f);
          bVar36 = bVar36 ^ bVar92;
          bVar37 = bVar37 ^ bVar92;
          bVar146 = (byte)uVar147 ^ bVar107;
          bVar148 = (byte)((ulong)uVar147 >> 8) ^ (char)bVar107 >> 7;
          bVar149 = (byte)((ulong)uVar147 >> 0x10) ^ (byte)((short)(char)bVar107 >> 0xf);
          bVar150 = (byte)((ulong)uVar147 >> 0x18) ^ (byte)((short)(char)bVar107 >> 0xf);
          bVar151 = (byte)((ulong)uVar147 >> 0x20) ^ bVar112;
          bVar152 = (byte)((ulong)uVar147 >> 0x28) ^ (char)bVar112 >> 7;
          bVar153 = (byte)((ulong)uVar147 >> 0x30) ^ (byte)((short)(char)bVar112 >> 0xf);
          bVar154 = (byte)((ulong)uVar147 >> 0x38) ^ (byte)((short)(char)bVar112 >> 0xf);
          uVar147 = CONCAT17(bVar154,CONCAT16(bVar153,CONCAT15(bVar152,CONCAT14(bVar151,CONCAT13(
                                                  bVar150,CONCAT12(bVar149,CONCAT11(bVar148,bVar146)
                                                                  ))))));
          bVar155 = (byte)uVar156 ^ bVar117;
          bVar157 = (byte)((ulong)uVar156 >> 8) ^ (char)bVar117 >> 7;
          bVar158 = (byte)((ulong)uVar156 >> 0x10) ^ (byte)((short)(char)bVar117 >> 0xf);
          bVar159 = (byte)((ulong)uVar156 >> 0x18) ^ (byte)((short)(char)bVar117 >> 0xf);
          bVar160 = (byte)((ulong)uVar156 >> 0x20) ^ bVar122;
          bVar161 = (byte)((ulong)uVar156 >> 0x28) ^ (char)bVar122 >> 7;
          bVar162 = (byte)((ulong)uVar156 >> 0x30) ^ (byte)((short)(char)bVar122 >> 0xf);
          bVar163 = (byte)((ulong)uVar156 >> 0x38) ^ (byte)((short)(char)bVar122 >> 0xf);
          uVar156 = CONCAT17(bVar163,CONCAT16(bVar162,CONCAT15(bVar161,CONCAT14(bVar160,CONCAT13(
                                                  bVar159,CONCAT12(bVar158,CONCAT11(bVar157,bVar155)
                                                                  ))))));
          bVar128 = (byte)uVar129 ^ bVar94;
          bVar130 = (byte)((ulong)uVar129 >> 8) ^ (char)bVar94 >> 7;
          bVar131 = (byte)((ulong)uVar129 >> 0x10) ^ (byte)((short)(char)bVar94 >> 0xf);
          bVar132 = (byte)((ulong)uVar129 >> 0x18) ^ (byte)((short)(char)bVar94 >> 0xf);
          bVar133 = (byte)((ulong)uVar129 >> 0x20) ^ bVar97;
          bVar134 = (byte)((ulong)uVar129 >> 0x28) ^ (char)bVar97 >> 7;
          bVar135 = (byte)((ulong)uVar129 >> 0x30) ^ (byte)((short)(char)bVar97 >> 0xf);
          bVar136 = (byte)((ulong)uVar129 >> 0x38) ^ (byte)((short)(char)bVar97 >> 0xf);
          uVar129 = CONCAT17(bVar136,CONCAT16(bVar135,CONCAT15(bVar134,CONCAT14(bVar133,CONCAT13(
                                                  bVar132,CONCAT12(bVar131,CONCAT11(bVar130,bVar128)
                                                                  ))))));
          bVar137 = (byte)uVar138 ^ bVar99;
          bVar139 = (byte)((ulong)uVar138 >> 8) ^ (char)bVar99 >> 7;
          bVar140 = (byte)((ulong)uVar138 >> 0x10) ^ (byte)((short)(char)bVar99 >> 0xf);
          bVar141 = (byte)((ulong)uVar138 >> 0x18) ^ (byte)((short)(char)bVar99 >> 0xf);
          bVar142 = (byte)((ulong)uVar138 >> 0x20) ^ bVar103;
          bVar143 = (byte)((ulong)uVar138 >> 0x28) ^ (char)bVar103 >> 7;
          bVar144 = (byte)((ulong)uVar138 >> 0x30) ^ (byte)((short)(char)bVar103 >> 0xf);
          bVar145 = (byte)((ulong)uVar138 >> 0x38) ^ (byte)((short)(char)bVar103 >> 0xf);
          uVar138 = CONCAT17(bVar145,CONCAT16(bVar144,CONCAT15(bVar143,CONCAT14(bVar142,CONCAT13(
                                                  bVar141,CONCAT12(bVar140,CONCAT11(bVar139,bVar137)
                                                                  ))))));
          bVar92 = (byte)uVar93 ^ bVar106;
          bVar94 = (byte)((ulong)uVar93 >> 8) ^ (char)bVar106 >> 7;
          bVar95 = (byte)((ulong)uVar93 >> 0x10) ^ bVar96;
          bVar96 = (byte)((ulong)uVar93 >> 0x18) ^ bVar96;
          bVar97 = (byte)((ulong)uVar93 >> 0x20) ^ bVar110;
          bVar98 = (byte)((ulong)uVar93 >> 0x28) ^ (char)bVar110 >> 7;
          bVar99 = (byte)((ulong)uVar93 >> 0x30) ^ bVar100;
          bVar100 = (byte)((ulong)uVar93 >> 0x38) ^ bVar100;
          uVar93 = CONCAT17(bVar100,CONCAT16(bVar99,CONCAT15(bVar98,CONCAT14(bVar97,CONCAT13(bVar96,
                                                  CONCAT12(bVar95,CONCAT11(bVar94,bVar92)))))));
          bVar101 = (byte)uVar102 ^ bVar115;
          bVar103 = (byte)((ulong)uVar102 >> 8) ^ (char)bVar115 >> 7;
          bVar104 = (byte)((ulong)uVar102 >> 0x10) ^ bVar105;
          bVar105 = (byte)((ulong)uVar102 >> 0x18) ^ bVar105;
          bVar106 = (byte)((ulong)uVar102 >> 0x20) ^ bVar119;
          bVar107 = (byte)((ulong)uVar102 >> 0x28) ^ (char)bVar119 >> 7;
          bVar108 = (byte)((ulong)uVar102 >> 0x30) ^ bVar109;
          bVar109 = (byte)((ulong)uVar102 >> 0x38) ^ bVar109;
          uVar102 = CONCAT17(bVar109,CONCAT16(bVar108,CONCAT15(bVar107,CONCAT14(bVar106,CONCAT13(
                                                  bVar105,CONCAT12(bVar104,CONCAT11(bVar103,bVar101)
                                                                  ))))));
          bVar110 = (byte)uVar111 ^ bVar113;
          bVar112 = (byte)((ulong)uVar111 >> 8) ^ (char)bVar113 >> 7;
          bVar114 = (byte)((short)(char)bVar113 >> 0xf);
          bVar113 = (byte)((ulong)uVar111 >> 0x10) ^ bVar114;
          bVar114 = (byte)((ulong)uVar111 >> 0x18) ^ bVar114;
          bVar115 = (byte)((ulong)uVar111 >> 0x20) ^ bVar116;
          bVar116 = (byte)((ulong)uVar111 >> 0x28) ^ (char)bVar116 >> 7;
          bVar118 = (byte)((int)uVar6 >> 0x1f);
          bVar117 = (byte)((ulong)uVar111 >> 0x30) ^ bVar118;
          bVar118 = (byte)((ulong)uVar111 >> 0x38) ^ bVar118;
          uVar111 = CONCAT17(bVar118,CONCAT16(bVar117,CONCAT15(bVar116,CONCAT14(bVar115,CONCAT13(
                                                  bVar114,CONCAT12(bVar113,CONCAT11(bVar112,bVar110)
                                                                  ))))));
          bVar119 = (byte)uVar120 ^ bVar121;
          bVar121 = (byte)((ulong)uVar120 >> 8) ^ (char)bVar121 >> 7;
          bVar123 = (byte)((int6)uVar7 >> 0x2f);
          bVar122 = (byte)((ulong)uVar120 >> 0x10) ^ bVar123;
          bVar123 = (byte)((ulong)uVar120 >> 0x18) ^ bVar123;
          bVar124 = (byte)((ulong)uVar120 >> 0x20) ^ bVar126;
          bVar125 = (byte)((ulong)uVar120 >> 0x28) ^ (char)bVar126 >> 7;
          bVar127 = (byte)((long)CONCAT17((char)bVar126 >> 7,CONCAT16(bVar126,uVar7)) >> 0x3f);
          bVar126 = (byte)((ulong)uVar120 >> 0x30) ^ bVar127;
          bVar127 = (byte)((ulong)uVar120 >> 0x38) ^ bVar127;
          uVar120 = CONCAT17(bVar127,CONCAT16(bVar126,CONCAT15(bVar125,CONCAT14(bVar124,CONCAT13(
                                                  bVar123,CONCAT12(bVar122,CONCAT11(bVar121,bVar119)
                                                                  ))))));
          puVar20 = puVar20 + 4;
          uVar18 = uVar18 - 0x20;
        } while (uVar18 != 0);
        bVar22 = bVar110 ^ bVar22 | bVar128 ^ bVar74 | bVar92 | bVar38 | bVar146 ^ bVar57;
        bVar23 = bVar112 ^ bVar23 | bVar130 ^ bVar76 | bVar94 | bVar42 | bVar148 ^ bVar58;
        bVar24 = bVar113 ^ bVar24 | bVar131 ^ bVar77 | bVar95 | bVar43 | bVar149 ^ bVar59;
        bVar25 = bVar114 ^ bVar25 | bVar132 ^ bVar78 | bVar96 | bVar44 | bVar150 ^ bVar60;
        bVar26 = bVar115 ^ bVar26 | bVar133 ^ bVar79 | bVar97 | bVar45 | bVar151 ^ bVar61;
        bVar27 = bVar116 ^ bVar27 | bVar134 ^ bVar80 | bVar98 | bVar46 | bVar152 ^ bVar62;
        bVar28 = bVar117 ^ bVar28 | bVar135 ^ bVar81 | bVar99 | bVar47 | bVar153 ^ bVar63;
        bVar29 = bVar118 ^ bVar29 | bVar136 ^ bVar82 | bVar100 | bVar48 | bVar154 ^ bVar64;
        bVar30 = bVar119 ^ bVar30 | bVar137 ^ bVar83 | bVar101 | bVar49 | bVar155 ^ bVar65;
        bVar31 = bVar121 ^ bVar31 | bVar139 ^ bVar85 | bVar103 | bVar50 | bVar157 ^ bVar67;
        bVar32 = bVar122 ^ bVar32 | bVar140 ^ bVar86 | bVar104 | bVar51 | bVar158 ^ bVar68;
        bVar33 = bVar123 ^ bVar33 | bVar141 ^ bVar87 | bVar105 | bVar52 | bVar159 ^ bVar69;
        bVar34 = bVar124 ^ bVar34 | bVar142 ^ bVar88 | bVar106 | bVar53 | bVar160 ^ bVar70;
        bVar35 = bVar125 ^ bVar35 | bVar143 ^ bVar89 | bVar107 | bVar54 | bVar161 ^ bVar71;
        bVar36 = bVar126 ^ bVar36 | bVar144 ^ bVar90 | bVar108 | bVar55 | bVar162 ^ bVar72;
        bVar37 = bVar127 ^ bVar37 | bVar145 ^ bVar91 | bVar109 | bVar56 | bVar163 ^ bVar73;
        auVar41[1] = bVar23;
        auVar41[0] = bVar22;
        auVar41[2] = bVar24;
        auVar41[3] = bVar25;
        auVar41[4] = bVar26;
        auVar41[5] = bVar27;
        auVar41[6] = bVar28;
        auVar41[7] = bVar29;
        auVar41[8] = bVar30;
        auVar41[9] = bVar31;
        auVar41[10] = bVar32;
        auVar41[0xb] = bVar33;
        auVar41[0xc] = bVar34;
        auVar41[0xd] = bVar35;
        auVar41[0xe] = bVar36;
        auVar41[0xf] = bVar37;
        auVar3[1] = bVar23;
        auVar3[0] = bVar22;
        auVar3[2] = bVar24;
        auVar3[3] = bVar25;
        auVar3[4] = bVar26;
        auVar3[5] = bVar27;
        auVar3[6] = bVar28;
        auVar3[7] = bVar29;
        auVar3[8] = bVar30;
        auVar3[9] = bVar31;
        auVar3[10] = bVar32;
        auVar3[0xb] = bVar33;
        auVar3[0xc] = bVar34;
        auVar3[0xd] = bVar35;
        auVar3[0xe] = bVar36;
        auVar3[0xf] = bVar37;
        auVar41 = NEON_ext(auVar41,auVar3,8,1);
        _checksum = CONCAT13(bVar25 ^ auVar41[3],
                             CONCAT12(bVar24 ^ auVar41[2],
                                      CONCAT11(bVar23 ^ auVar41[1],bVar22 ^ auVar41[0]))) ^
                    CONCAT13(bVar29 ^ auVar41[7],
                             CONCAT12(bVar28 ^ auVar41[6],
                                      CONCAT11(bVar27 ^ auVar41[5],bVar26 ^ auVar41[4])));
        if (uVar17 != uVar16) {
          uVar18 = uVar17;
          if ((_i & 0x18) == 0) goto LAB_100003d08;
          goto LAB_100003ca4;
        }
      }
      _j = _i;
      if (_checksum != 0) {
        _puts("Checksum failed! Exiting now...");
        _fflush(*(FILE **)puVar11);
                    /* WARNING: Subroutine does not return */
        _exit(1);
      }
    }
    _puts("Checksum is correct!");
    _fflush(*(FILE **)puVar11);
    uVar15 = 0;
    goto LAB_100003d54;
  }
LAB_100003b8c:
  _fprintf(*(FILE **)PTR____stderrp_100004018,"Usage: %s -t <timeout> -w <workdir> [-d]\n");
  uVar15 = 1;
LAB_100003d54:
  if (*(long *)PTR____stack_chk_guard_100004010 != local_68) {
                    /* WARNING: Subroutine does not return */
    ___stack_chk_fail(uVar15);
  }
  return;
}


void ___stack_chk_fail(void)

{
                    /* WARNING: Could not recover jumptable at 0x000100003db8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR____stack_chk_fail_100004008)();
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uint _alarm(uint param_1)

{
  uint uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003dc4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)PTR__alarm_100004028)(param_1);
  return uVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _atoi(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003dd0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__atoi_100004030)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _chdir(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003ddc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__chdir_100004038)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _exit(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003de8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__exit_100004040)(param_1);
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fflush(FILE *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003df4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fflush_100004048)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _fprintf(FILE *param_1,char *param_2,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__fprintf_100004050)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _getchar(void)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__getchar_100004058)();
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _getcwd(char *param_1,size_t param_2)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__getcwd_100004060)();
  return pcVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _getopt(int param_1,char *param_2,char *param_3)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__getopt_100004068)(param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

uid_t _getuid(void)

{
  uid_t uVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)PTR__getuid_100004070)();
  return uVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _printf(char *param_1,...)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__printf_100004080)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int _puts(char *param_1)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR__puts_100004088)((int)param_1);
  return iVar1;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _signal(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000100003e54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR__signal_100004090)(param_1);
  return;
}


/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * _strdup(char *param_1)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000100003e60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = (char *)(*(code *)PTR__strdup_100004098)();
  return pcVar1;
}


/* WARNING: Control flow encountered bad instruction data */

void ___chkstk_darwin(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


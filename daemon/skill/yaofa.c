// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// yaofa
inherit SPELLS;

string name() { return "����"; }

int is_exclusive() { return 1; }

int valid_enable(string usage) { return usage=="spells"; }

int practice_skill(object me)
{
    object env = environment(me);
    if (!env
    ||  !env->query("lianxi_yaofa")
    ||  (int)me->query_temp("mark/�޵׶���ħ̨climbed") != 1)
        return notify_fail("ֻ��������ħ̨�ϲſ�������������\n");
    env->practice_yaofa(me);
    return 1;
}

string cast_spell_file(string spell)
{
        return CLASS_D("yushu") + "/yaofa/"+spell;
}



// ALI by NewX

#include <armor.h>

inherit WAIST;

void create()
{
    set_name( "Ů������", ({ "queen waist", "waist" }) );
    set_weight(2000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", @LONG
һ����ڷ�����Ƥ�£����ϻ���������������
��ǰ��һ����׿������Ը���ס�鷿�������һƬ��׿������Ը���ס˽����
��¶���ԸУ�ɢ����SMŮ���ı�Ű��Ϣ��
LONG);
        set("unit", "��");
        set("value", 400);
        set("material", "leather");
        set("armor_prop/armor", 10);
        set("armor_prop/dodge", 10);
        set("armor_prop/personality", 5);
//        set("wear_msg", "$Nȡ����һ���Ըе�Ƥ�´��ϣ���ʱ�����Ϊһ���Ըе�SMŮ����\n");
        set("female_only", 1);
    }

    setup();
}


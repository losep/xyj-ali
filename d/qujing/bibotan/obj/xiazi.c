// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit ITEM;

void create()
{
        set_name("�ƽ�ϻ��", ({ "xiazi" }) );
        set_weight(2000);
        set_max_encumbrance(1200);
        if( clonep() ) {
                object ob;
     int i;
     i=random(3);
     seteuid(getuid());
     if(i >=2) {
        ob=new("/d/qujing/bibotan/obj/tooth");
     ob->move(this_object());
     } 
/*
else if(i>=1) {
                        ob=new("/d/obj/book/baguatu");
                } else  {
                        ob=new("/d/obj/book/xuanhu-blade");
                }
     ob->move(this_object());
*/
              set_default_object(__FILE__);
        } else {
                set("unit", "��");
     set("no_sell", 1);
     set("no_put", 1);
     set("no_give", 1);
                set("long", "һ������Ȼ�Ļƽ�ϻ�ӡ�\n");
                set("value",0);
        }
}

int is_container() { return 1; }


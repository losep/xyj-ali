// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// by snowcat 12/8/1997


inherit NPC;
inherit F_VENDOR;

void create()
{
  set_name("ʷ�ϰ�", ({"shi laoban", "shi", "laoban"}));
  set("gender", "����");
  set("combat_exp", 5000);
  set("age", 30);
  set("per", 21);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ([
        "zhulan": "/d/qujing/tianzhu/obj/zhulan",
        "zhulou": "/d/qujing/tianzhu/obj/zhulou",
        "zhupa": "/d/qujing/tianzhu/obj/zhupa",
        "zhubian": "/d/qujing/tianzhu/obj/zhubian",
        "zhudao": "/d/obj/weapon/blade/zhudao",
        "zhujian": "/d/obj/weapon/sword/zhujian",
      ]) );

  setup();
  carry_object("/d/qujing/tianzhu/obj/baipao")->wear();
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}


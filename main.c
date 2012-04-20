/* main.cpp -- by lizhonglei 2008-05-23 */਍⌀搀攀昀椀渀攀 唀一䤀䌀伀䐀䔀ഀ
#include <windows.h>਍⌀椀渀挀氀甀搀攀 ∀爀攀猀漀甀爀挀攀⸀栀∀ഀ
#include "tetris.h"਍⌀椀渀挀氀甀搀攀 ∀猀挀漀爀攀⸀栀∀ഀ
#include "log.h"਍⼀⼀最氀漀戀愀氀 ഀ
਍⌀搀攀昀椀渀攀 戀氀漀挀欀开眀椀搀琀栀ऀ㈀　ഀ
#define TIMER_ID	1001਍⌀搀攀昀椀渀攀 䔀䰀䄀倀匀䔀ऀऀ㔀　　ഀ
਍猀琀爀甀挀琀 氀漀最 洀礀氀漀最㬀ഀ
਍猀琀爀甀挀琀 琀攀琀爀椀猀 琀㬀ഀ
struct score s;਍ഀ
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM) ;਍椀渀琀 圀䤀一䄀倀䤀 圀椀渀䴀愀椀渀⠀䠀䤀一匀吀䄀一䌀䔀 栀䤀渀猀琀愀渀挀攀Ⰰ 䠀䤀一匀吀䄀一䌀䔀 栀倀爀攀瘀䤀渀猀琀愀渀挀攀Ⰰ  倀匀吀刀 猀稀䌀洀搀䰀椀渀攀Ⰰ 椀渀琀 椀䌀洀搀匀栀漀眀⤀ഀ
{਍        圀一䐀䌀䰀䄀匀匀 眀渀搀挀氀愀猀猀㬀ഀ
	HWND hwnd;਍ऀ䴀匀䜀 洀猀最㬀ഀ
	TCHAR app_name[]=TEXT("tetris");਍ऀ䠀䴀䔀一唀 栀䴀攀渀甀㬀ഀ
        int x_size;਍        椀渀琀 礀开猀椀稀攀㬀 ⼀⼀猀椀稀攀ഀ
        int x,y; //position਍ഀ
        //init ਍        洀开椀渀椀琀⠀☀琀Ⰰ㄀㈀Ⰰ㈀㐀⤀㬀ഀ
        x_size=m_get_x(&t)*block_width+100;਍        礀开猀椀稀攀㴀洀开最攀琀开礀⠀☀琀⤀⨀戀氀漀挀欀开眀椀搀琀栀⬀䜀攀琀匀礀猀琀攀洀䴀攀琀爀椀挀猀⠀匀䴀开䌀夀䌀䄀倀吀䤀伀一⤀⬀㄀　㬀ഀ
        x=(GetSystemMetrics(SM_CXFULLSCREEN)-x_size)/2;਍        礀㴀⠀䜀攀琀匀礀猀琀攀洀䴀攀琀爀椀挀猀⠀匀䴀开䌀夀䘀唀䰀䰀匀䌀刀䔀䔀一⤀ⴀ礀开猀椀稀攀⤀⼀㈀㬀ഀ
        s_init(&s,"lizhonglei");਍        氀开椀渀椀琀⠀☀洀礀氀漀最Ⰰ∀氀漀最⸀琀砀琀∀⤀㬀ഀ
        mylog.level=4; //control਍        ⼀⼀ 氀开椀渀昀漀⠀☀洀礀氀漀最Ⰰ∀猀琀愀爀琀 氀漀最∀⤀㬀ഀ
        // create view਍ऀ眀渀搀挀氀愀猀猀⸀氀瀀猀稀䌀氀愀猀猀一愀洀攀㴀愀瀀瀀开渀愀洀攀㬀ഀ
        wndclass.style=CS_HREDRAW | CS_VREDRAW ;਍ऀ眀渀搀挀氀愀猀猀⸀栀䤀挀漀渀㴀䰀漀愀搀䤀洀愀最攀⠀栀䤀渀猀琀愀渀挀攀Ⰰ䴀䄀䬀䔀䤀一吀刀䔀匀伀唀刀䌀䔀⠀䤀䐀䤀开吀䔀吀刀䤀匀⤀Ⰰ䤀䴀䄀䜀䔀开䤀䌀伀一Ⰰ　Ⰰ　Ⰰ 䰀刀开䐀䔀䘀䄀唀䰀吀匀䤀娀䔀簀䰀刀开䐀䔀䘀䄀唀䰀吀䌀伀䰀伀刀⤀㬀ഀ
਍ऀ眀渀搀挀氀愀猀猀⸀氀瀀昀渀圀渀搀倀爀漀挀㴀圀渀搀倀爀漀挀㬀ഀ
	wndclass.hInstance=hInstance;਍ऀ眀渀搀挀氀愀猀猀⸀栀䌀甀爀猀漀爀㴀䰀漀愀搀䌀甀爀猀漀爀⠀一唀䰀䰀Ⰰ䤀䐀䌀开䄀刀刀伀圀⤀㬀ഀ
	wndclass.cbClsExtra=0 ;਍        眀渀搀挀氀愀猀猀⸀挀戀圀渀搀䔀砀琀爀愀㴀　 㬀ഀ
        wndclass.hbrBackground=(HBRUSH)COLOR_WINDOW;਍ऀ眀渀搀挀氀愀猀猀⸀氀瀀猀稀䴀攀渀甀一愀洀攀㴀一唀䰀䰀㬀ഀ
	if (!RegisterClass (&wndclass)){਍ऀऀ䴀攀猀猀愀最攀䈀漀砀⠀一唀䰀䰀Ⰰ吀䔀堀吀⠀∀豬ㅑ╙⊍⤀Ⰰ吀䔀堀吀⠀∀昀䪋≔⤀Ⰰ䴀䈀开伀䬀⤀㬀ഀ
		return -1;਍ऀ紀ഀ
	਍ऀ栀眀渀搀㴀䌀爀攀愀琀攀圀椀渀搀漀眀⠀愀瀀瀀开渀愀洀攀Ⰰ吀䔀堀吀⠀∀쐀坏꽿륥坥≗⤀Ⰰ圀匀开䌀䄀倀吀䤀伀一簀圀匀开匀夀匀䴀䔀一唀  Ⰰ砀Ⰰ礀Ⰰഀ
                          x_size,y_size,NULL,NULL,hInstance,NULL);਍ഀ
	ShowWindow(hwnd,iCmdShow);਍ऀ唀瀀搀愀琀攀圀椀渀搀漀眀⠀栀眀渀搀⤀㬀ഀ
	while(GetMessage(&msg,NULL,0,0)){਍ऀऀ吀爀愀渀猀氀愀琀攀䴀攀猀猀愀最攀⠀☀洀猀最⤀㬀ഀ
		DispatchMessage(&msg);਍ऀ紀ഀ
        // ਍        氀开挀氀漀猀攀⠀☀洀礀氀漀最⤀㬀ഀ
        m_free(&t);਍        爀攀琀甀爀渀 洀猀最⸀眀倀愀爀愀洀㬀  ഀ
}਍䰀刀䔀匀唀䰀吀 䌀䄀䰀䰀䈀䄀䌀䬀 圀渀搀倀爀漀挀⠀䠀圀一䐀 栀眀渀搀Ⰰ 唀䤀一吀 洀攀猀猀愀最攀Ⰰ 圀倀䄀刀䄀䴀 眀倀愀爀愀洀Ⰰ 䰀倀䄀刀䄀䴀 氀倀愀爀愀洀⤀ഀ
{਍        䠀䐀䌀 栀搀挀㬀ഀ
        PAINTSTRUCT ps;਍ऀऀ䌀刀䔀䄀吀䔀匀吀刀唀䌀吀 ⨀挀猀㬀ഀ
		static HINSTANCE hi;਍ऀऀ猀琀愀琀椀挀 栀椀挀漀渀㬀ഀ
        int i,j;਍        椀渀琀 琀洀瀀开猀挀漀爀攀㬀ഀ
		int ret;਍        ⼀⼀ 䠀倀䔀一 栀瀀攀渀㬀ഀ
        switch(message){਍        挀愀猀攀 圀䴀开䌀刀䔀䄀吀䔀㨀ऀഀ
				cs=(CREATESTRUCT*)lParam;਍ऀऀऀऀ栀椀㴀挀猀ⴀ㸀栀䤀渀猀琀愀渀挀攀㬀ഀ
				//hicon=LoadImage(hi,MAKEINTRESOURCE(IDI_TETRIS),IMAGE_ICON,16,16, LR_DEFAULTCOLOR);				਍                爀攀琀甀爀渀 　㬀ഀ
        case WM_DESTROY:਍                倀漀猀琀儀甀椀琀䴀攀猀猀愀最攀 ⠀　⤀ 㬀ഀ
                return 0;਍        挀愀猀攀 圀䴀开倀䄀䤀一吀㨀ഀ
                hdc=BeginPaint(hwnd,&ps);਍                ⼀⼀ 琀攀砀琀ഀ
                TextOut(hdc,m_get_x(&t)*20+5,10,TEXT("开始 回车"),5);਍                吀攀砀琀伀甀琀⠀栀搀挀Ⰰ洀开最攀琀开砀⠀☀琀⤀⨀㈀　⬀㔀Ⰰ㐀　Ⰰ吀䔀堀吀⠀∀ഀ上   w"),5);਍                吀攀砀琀伀甀琀⠀栀搀挀Ⰰ洀开最攀琀开砀⠀☀琀⤀⨀㈀　⬀㔀Ⰰ㜀　Ⰰ吀䔀堀吀⠀∀଀⁎  猀∀⤀Ⰰ㔀⤀㬀ഀ
                TextOut(hdc,m_get_x(&t)*20+5,100,TEXT("左   a"),5);਍                吀攀砀琀伀甀琀⠀栀搀挀Ⰰ洀开最攀琀开砀⠀☀琀⤀⨀㈀　⬀㔀Ⰰ㄀㌀　Ⰰ吀䔀堀吀⠀∀⁓  搀∀⤀Ⰰ㔀⤀㬀ഀ
                TextOut(hdc,m_get_x(&t)*20+5,160,TEXT("旋转  j"),5);਍                吀攀砀琀伀甀琀⠀栀搀挀Ⰰ洀开最攀琀开砀⠀☀琀⤀⨀㈀　⬀㔀Ⰰ㄀㤀　Ⰰ吀䔀堀吀⠀∀尀扐⁫椀∀⤀Ⰰ㔀⤀㬀ഀ
				TextOut(hdc,m_get_x(&t)*20+5,190,TEXT("速降 空格"),5);਍ऀऀऀऀ椀昀⠀琀⸀瀀氀愀礀椀渀最℀㴀倀开匀吀伀倀⤀笀ഀ
						wchar_t tmp[256];਍ऀऀऀऀऀऀ眀猀瀀爀椀渀琀昀⠀琀洀瀀Ⰰ䰀∀─猀 ─　㌀搀∀Ⰰ吀䔀堀吀⠀∀需ٟ≒⤀Ⰰ猀开最攀琀猀挀漀爀攀⠀☀猀⤀⤀㬀ഀ
						TextOut(hdc,m_get_x(&t)*20+5,250,tmp,6);਍ऀऀऀऀ紀ഀ
				else{਍ऀऀऀऀऀऀ眀挀栀愀爀开琀 琀洀瀀嬀㈀㔀㘀崀㬀ഀ
						wsprintf(tmp,L"%s",TEXT("游戏结束"));਍ऀऀऀऀऀऀ吀攀砀琀伀甀琀⠀栀搀挀Ⰰ洀开最攀琀开砀⠀☀琀⤀⨀㈀　⬀㔀Ⰰ㈀㔀　Ⰰ琀洀瀀Ⰰ㐀⤀㬀ഀ
				}਍                ⼀⼀ 挀漀氀甀洀渀猀ഀ
                for(i=1;i<m_get_x(&t)+1;i++){਍                        䴀漀瘀攀吀漀䔀砀⠀栀搀挀Ⰰ椀⨀戀氀漀挀欀开眀椀搀琀栀Ⰰ　Ⰰ一唀䰀䰀⤀㬀ഀ
                        LineTo(hdc,i*block_width,m_get_y(&t)*block_width);਍                紀ഀ
                // rows਍                昀漀爀⠀椀㴀㄀㬀椀㰀洀开最攀琀开礀⠀☀琀⤀⬀㄀㬀椀⬀⬀⤀笀ഀ
                        MoveToEx(hdc,0,i*block_width,NULL);਍                        䰀椀渀攀吀漀⠀栀搀挀Ⰰ洀开最攀琀开砀⠀☀琀⤀⨀戀氀漀挀欀开眀椀搀琀栀Ⰰ椀⨀戀氀漀挀欀开眀椀搀琀栀⤀㬀ഀ
                }਍                ⼀⼀ 洀愀琀爀椀挀猀ഀ
                for(i=0;i<m_get_x(&t);i++){਍                        昀漀爀⠀樀㴀　㬀樀㰀洀开最攀琀开礀⠀☀琀⤀㬀樀⬀⬀⤀笀ഀ
                                if(m_get_state(&t,i,j)==1){// paint਍                                        ⼀⼀ 挀栀愀爀 琀洀瀀嬀㈀㔀㘀崀㬀ഀ
                                        //sprintf(tmp,"state:%d",m_get_state(&t,i,j));਍                                        ⼀⼀氀开椀渀昀漀⠀☀洀礀氀漀最Ⰰ琀洀瀀⤀㬀ഀ
                                        SelectObject (hdc, GetStockObject (GRAY_BRUSH));਍                                        刀攀挀琀愀渀最氀攀⠀栀搀挀Ⰰ椀⨀㈀　⬀㈀Ⰰ樀⨀㈀　⬀㈀Ⰰ椀⨀㈀　⬀㄀㠀Ⰰ樀⨀㈀　⬀㄀㠀⤀㬀ഀ
                                }਍                        紀ഀ
                }਍                䔀渀搀倀愀椀渀琀⠀栀眀渀搀Ⰰ☀瀀猀⤀㬀ऀഀ
                return 0;਍       ഀ
        case WM_CHAR:਍                猀眀椀琀挀栀⠀眀倀愀爀愀洀⤀笀ഀ
                case 'a':	਍                        爀攀琀㴀洀开氀攀昀琀⠀☀琀⤀㬀ഀ
						if(ret==-1) return 0;਍                        戀爀攀愀欀㬀ഀ
                case 's':਍                        琀洀瀀开猀挀漀爀攀㴀洀开搀漀眀渀⠀☀琀⤀㬀ഀ
						if(tmp_score!=0){਍ऀऀऀऀऀऀऀऀ爀攀琀㴀挀爀攀愀琀攀开最爀愀瀀栀椀挀⠀☀琀⤀ 㬀⼀⼀ 渀攀眀 最爀愀瀀栀椀挀ഀ
								if(ret==-1){//game over਍ऀऀऀऀऀऀऀऀऀऀ䬀椀氀氀吀椀洀攀爀⠀栀眀渀搀Ⰰ吀䤀䴀䔀刀开䤀䐀⤀㬀ഀ
										m_end(&t);਍ऀऀऀऀऀऀऀऀऀऀ䤀渀瘀愀氀椀搀愀琀攀刀攀挀琀⠀栀眀渀搀Ⰰ一唀䰀䰀Ⰰ吀刀唀䔀⤀㬀ഀ
										return 0;਍ऀऀऀऀऀऀऀऀ紀ഀ
						}਍ऀऀऀऀऀऀ椀昀⠀琀洀瀀开猀挀漀爀攀㸀　⤀笀ഀ
								SetTimer(hwnd,TIMER_ID,ELAPSE-s_getscore(&s),NULL);਍ऀऀऀऀऀऀऀऀ猀开愀搀搀猀挀漀爀攀⠀☀猀Ⰰ琀洀瀀开猀挀漀爀攀⤀㬀ഀ
						}਍ऀऀऀऀऀऀ⼀⼀ 爀攀 瀀愀椀渀琀ഀ
						if(tmp_score!=-1){਍ऀऀऀऀऀऀऀऀ䤀渀瘀愀氀椀搀愀琀攀刀攀挀琀⠀栀眀渀搀Ⰰ一唀䰀䰀Ⰰ吀刀唀䔀⤀㬀ഀ
								return 0;਍ऀऀऀऀऀऀ紀ഀ
                        else return 0;਍                        ഀ
                case 'w':਍                        爀攀琀㴀洀开甀瀀⠀☀琀⤀㬀ഀ
						if(ret==-1) return 0;਍                        戀爀攀愀欀㬀ഀ
                case 'd':਍                        爀攀琀㴀洀开爀椀最栀琀⠀☀琀⤀㬀ഀ
						if(ret==-1) return 0;਍                        戀爀攀愀欀㬀ഀ
                case 'j':਍                        爀攀琀㴀洀开爀漀琀愀琀攀⠀☀琀⤀㬀ഀ
						if(ret==-1) return 0;਍                        戀爀攀愀欀㬀ഀ
                case 'i':਍                        ⼀⼀洀开昀爀攀攀⠀☀琀⤀㬀ഀ
						m_end(&t);਍                        䬀椀氀氀吀椀洀攀爀⠀栀眀渀搀Ⰰ吀䤀䴀䔀刀开䤀䐀⤀㬀ഀ
                        break;਍                挀愀猀攀 ✀ ✀㨀ഀ
                        tmp_score=m_ddown(&t);਍                        椀昀⠀琀洀瀀开猀挀漀爀攀℀㴀　⤀笀ഀ
								ret=create_graphic(&t) ;// new graphic਍ऀऀऀऀऀऀऀऀ椀昀⠀爀攀琀㴀㴀ⴀ㄀⤀笀⼀⼀最愀洀攀 漀瘀攀爀ഀ
										KillTimer(hwnd,TIMER_ID);਍ऀऀऀऀऀऀऀऀऀऀ洀开攀渀搀⠀☀琀⤀㬀ഀ
										InvalidateRect(hwnd,NULL,TRUE);਍ऀऀऀऀऀऀऀऀऀऀ爀攀琀甀爀渀 　㬀ഀ
								}਍ऀऀऀऀऀऀ紀ഀ
						if(tmp_score>0){਍ऀऀऀऀऀऀऀऀ匀攀琀吀椀洀攀爀⠀栀眀渀搀Ⰰ吀䤀䴀䔀刀开䤀䐀Ⰰ䔀䰀䄀倀匀䔀ⴀ猀开最攀琀猀挀漀爀攀⠀☀猀⤀Ⰰ一唀䰀䰀⤀㬀ഀ
								s_addscore(&s,tmp_score);਍ऀऀऀऀऀऀ紀ഀ
						// re paint਍ऀऀऀऀऀऀ椀昀⠀琀洀瀀开猀挀漀爀攀℀㴀ⴀ㄀⤀笀ഀ
								InvalidateRect(hwnd,NULL,TRUE);਍ऀऀऀऀऀऀऀऀ爀攀琀甀爀渀 　㬀ഀ
						}਍                        攀氀猀攀 爀攀琀甀爀渀 　㬀ഀ
                case '\r':਍                        洀开猀琀愀爀琀⠀☀琀⤀㬀ഀ
                        SetTimer(hwnd,TIMER_ID,ELAPSE,NULL);// create timer to down autolly਍                        戀爀攀愀欀㬀ഀ
                }਍                ⼀⼀ 爀攀 瀀愀椀渀琀ഀ
                InvalidateRect(hwnd,NULL,TRUE);਍                爀攀琀甀爀渀 　㬀ഀ
        case WM_TIMER: // 很简单, 直接往下移动一格਍                ⼀⼀䴀攀猀猀愀最攀䈀漀砀⠀一唀䰀䰀Ⰰ吀䔀堀吀⠀∀栀攀栀攀∀⤀Ⰰ吀䔀堀吀⠀∀愀氀攀爀琀∀⤀Ⰰ䴀䈀开伀䬀⤀㬀ഀ
                tmp_score=m_down(&t);਍ऀऀऀऀ椀昀⠀琀洀瀀开猀挀漀爀攀℀㴀　⤀笀ഀ
						ret=create_graphic(&t) ;// new graphic਍ऀऀऀऀऀऀ椀昀⠀爀攀琀㴀㴀ⴀ㄀⤀笀⼀⼀最愀洀攀 漀瘀攀爀ഀ
								KillTimer(hwnd,TIMER_ID);਍ऀऀऀऀऀऀऀऀ洀开攀渀搀⠀☀琀⤀㬀ഀ
								InvalidateRect(hwnd,NULL,TRUE);਍ऀऀऀऀऀऀऀऀ爀攀琀甀爀渀 　㬀ഀ
						}਍ऀऀऀऀ紀ഀ
				if(tmp_score>0){਍ऀऀऀऀऀऀ匀攀琀吀椀洀攀爀⠀栀眀渀搀Ⰰ吀䤀䴀䔀刀开䤀䐀Ⰰ䔀䰀䄀倀匀䔀ⴀ猀开最攀琀猀挀漀爀攀⠀☀猀⤀Ⰰ一唀䰀䰀⤀㬀ഀ
						s_addscore(&s,tmp_score);਍ऀऀऀऀ紀ഀ
                // re paint਍ऀऀऀऀ椀昀⠀琀洀瀀开猀挀漀爀攀℀㴀ⴀ㄀⤀笀ഀ
						InvalidateRect(hwnd,NULL,TRUE);਍ऀऀऀऀ紀ഀ
                return 0;਍        紀ऀഀ
਍        爀攀琀甀爀渀 䐀攀昀圀椀渀搀漀眀倀爀漀挀 ⠀栀眀渀搀Ⰰ 洀攀猀猀愀最攀Ⰰ 眀倀愀爀愀洀Ⰰ 氀倀愀爀愀洀⤀ 㬀ഀ
}਍ഀ

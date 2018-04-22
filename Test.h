/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  PANEL                            1
#define  PANEL_PLOT                       2       /* control type: command, callback function: PLOT */
#define  PANEL_RST                        3       /* control type: command, callback function: RST */
#define  PANEL_Quit                       4       /* control type: command, callback function: Quit1 */
#define  PANEL_Go                         5       /* control type: binary, callback function: Go1 */
#define  PANEL_V_Pos                      6       /* control type: scale, callback function: (none) */
#define  PANEL_RG                         7       /* control type: numeric, callback function: (none) */
#define  PANEL_Z0                         8       /* control type: numeric, callback function: (none) */
#define  PANEL_Longtitude                 9       /* control type: numeric, callback function: LENGTH */
#define  PANEL_VSource                    10      /* control type: numeric, callback function: (none) */
#define  PANEL_L                          11      /* control type: numeric, callback function: (none) */
#define  PANEL_Er                         12      /* control type: numeric, callback function: (none) */
#define  PANEL_Il                         13      /* control type: numeric, callback function: (none) */
#define  PANEL_Vl                         14      /* control type: numeric, callback function: (none) */
#define  PANEL_R_Pic                      15      /* control type: picture, callback function: (none) */
#define  PANEL_L_Pic                      16      /* control type: picture, callback function: (none) */
#define  PANEL_SPLITTER_4                 17      /* control type: splitter, callback function: (none) */
#define  PANEL_SPLITTER_3                 18      /* control type: splitter, callback function: (none) */
#define  PANEL_SPLITTER_2                 19      /* control type: splitter, callback function: (none) */
#define  PANEL_SPLITTER                   20      /* control type: splitter, callback function: (none) */
#define  PANEL_Lin1                       21      /* control type: slide, callback function: (none) */
#define  PANEL_SPLITTER_9                 22      /* control type: splitter, callback function: (none) */
#define  PANEL_SPLITTER_8                 23      /* control type: splitter, callback function: (none) */
#define  PANEL_SPLITTER_7                 24      /* control type: splitter, callback function: (none) */
#define  PANEL_SPLITTER_6                 25      /* control type: splitter, callback function: (none) */
#define  PANEL_SPLITTER_5                 26      /* control type: splitter, callback function: (none) */
#define  PANEL_Vph                        27      /* control type: numeric, callback function: (none) */
#define  PANEL_V_Pic                      28      /* control type: picture, callback function: (none) */
#define  PANEL_Check_Point                29      /* control type: numeric, callback function: (none) */
#define  PANEL_CANVAS                     30      /* control type: canvas, callback function: (none) */
#define  PANEL_STRING                     31      /* control type: string, callback function: (none) */
#define  PANEL_TIMER                      32      /* control type: timer, callback function: TIMER1 */
#define  PANEL_STRING_2                   33      /* control type: string, callback function: (none) */

#define  PANEL_2                          2
#define  PANEL_2_GRAPH_2                  2       /* control type: graph, callback function: (none) */
#define  PANEL_2_GRAPH                    3       /* control type: graph, callback function: (none) */
#define  PANEL_2_Quit2                    4       /* control type: command, callback function: Quit2 */
#define  PANEL_2_I_GRAPH                  5       /* control type: numeric, callback function: (none) */
#define  PANEL_2_T_IL                     6       /* control type: numeric, callback function: (none) */
#define  PANEL_2_VL_GRAPH                 7       /* control type: numeric, callback function: (none) */
#define  PANEL_2_T_VL                     8       /* control type: numeric, callback function: (none) */
#define  PANEL_2_Cursor                   9       /* control type: timer, callback function: Cursor */

#define  PANEL_3                          3
#define  PANEL_3_Quit                     2       /* control type: command, callback function: Quit */
#define  PANEL_3_Resistor                 3       /* control type: command, callback function: Resistor */
#define  PANEL_3_DiffEquation             4       /* control type: command, callback function: Diff */
#define  PANEL_3_STRING                   5       /* control type: string, callback function: (none) */

#define  PANEL_4                          4
#define  PANEL_4_PLOT                     2       /* control type: command, callback function: PLOT */
#define  PANEL_4_RST                      3       /* control type: command, callback function: RST */
#define  PANEL_4_Quit                     4       /* control type: command, callback function: Quit3 */
#define  PANEL_4_Go                       5       /* control type: binary, callback function: Go2 */
#define  PANEL_4_V_Pos                    6       /* control type: scale, callback function: (none) */
#define  PANEL_4_RG                       7       /* control type: numeric, callback function: (none) */
#define  PANEL_4_Z0                       8       /* control type: numeric, callback function: (none) */
#define  PANEL_4_Longtitude               9       /* control type: numeric, callback function: LENGTH1 */
#define  PANEL_4_VSource                  10      /* control type: numeric, callback function: (none) */
#define  PANEL_4_RL                       11      /* control type: numeric, callback function: (none) */
#define  PANEL_4_Er                       12      /* control type: numeric, callback function: (none) */
#define  PANEL_4_Il                       13      /* control type: numeric, callback function: (none) */
#define  PANEL_4_Vl                       14      /* control type: numeric, callback function: (none) */
#define  PANEL_4_R_Pic                    15      /* control type: picture, callback function: (none) */
#define  PANEL_4_Lin1                     16      /* control type: slide, callback function: (none) */
#define  PANEL_4_Vph                      17      /* control type: numeric, callback function: (none) */
#define  PANEL_4_V_Pic                    18      /* control type: picture, callback function: (none) */
#define  PANEL_4_Check_Point              19      /* control type: numeric, callback function: (none) */
#define  PANEL_4_CANVAS                   20      /* control type: canvas, callback function: (none) */
#define  PANEL_4_STRING                   21      /* control type: string, callback function: (none) */
#define  PANEL_4_TIMER                    22      /* control type: timer, callback function: TIMER2 */
#define  PANEL_4_STRING_2                 23      /* control type: string, callback function: (none) */
#define  PANEL_4_RL1                      24      /* control type: picture, callback function: (none) */
#define  PANEL_4_SPLITTER_4               25      /* control type: splitter, callback function: (none) */
#define  PANEL_4_SPLITTER_3               26      /* control type: splitter, callback function: (none) */
#define  PANEL_4_SPLITTER_2               27      /* control type: splitter, callback function: (none) */
#define  PANEL_4_SPLITTER                 28      /* control type: splitter, callback function: (none) */
#define  PANEL_4_SPLITTER_9               29      /* control type: splitter, callback function: (none) */
#define  PANEL_4_SPLITTER_8               30      /* control type: splitter, callback function: (none) */
#define  PANEL_4_SPLITTER_7               31      /* control type: splitter, callback function: (none) */
#define  PANEL_4_SPLITTER_6               32      /* control type: splitter, callback function: (none) */
#define  PANEL_4_SPLITTER_5               33      /* control type: splitter, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Cursor(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Diff(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Go1(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Go2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK LENGTH(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK LENGTH1(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK PLOT(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Quit(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Quit1(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Quit2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Quit3(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Resistor(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK RST(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK TIMER1(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK TIMER2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif

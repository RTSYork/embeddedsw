/******************************************************************************
*
* Copyright (C) 2017 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* XILINX CONSORTIUM BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/
/*****************************************************************************/
/**
*
* @file dppt_vid_phy_config.h
*
* This file contains functions to configure Video Pattern Generator core.
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver   Who    Date     Changes
* ----- ------ -------- --------------------------------------------------
* 1.00  KI    07/13/17 Initial release.
* </pre>
*
******************************************************************************/

#include <stdio.h>
#include "xbasic_types.h"
#include "xil_types.h"
#include "xparameters.h"
#include "xvphy.h"

typedef enum {
        ONBOARD_REF_CLK = 1,
        DP159_FORWARDED_CLK,
} XVphy_User_GT_RefClk_Src;

typedef struct {
        u8 Index;
        XVphy_PllType  TxPLL;
        XVphy_PllType  RxPLL;
        XVphy_ChannelId TxChId;
        XVphy_ChannelId RxChId;
        u32 LineRate;
        u64 LineRateHz;
        XVphy_User_GT_RefClk_Src QPLLRefClkSrc;
        XVphy_User_GT_RefClk_Src CPLLRefClkSrc;
        u64 QPLLRefClkFreqHz;
        u64 CPLLRefClkFreqHz;
} XVphy_User_Config;

static XVphy_User_Config PHY_User_Config_Table[] =
{
  // Index,         TxPLL,               RxPLL,
//		TxChId,                    RxChId,         LineRate,
//		LineRateHz,                QPLLRefClkSrc,
//		CPLLRefClkSrc,       QPLLRefClkFreqHz,    CPLLRefClkFreqHz
  {   0,     XVPHY_PLL_TYPE_QPLL,   XVPHY_PLL_TYPE_CPLL,
		  XVPHY_CHANNEL_ID_CMN,     XVPHY_CHANNEL_ID_CHA,     0x06,
		  XVPHY_DP_LINK_RATE_HZ_162GBPS,      ONBOARD_REF_CLK,
		  DP159_FORWARDED_CLK,        162000000,           81000000        },
  {   1,     XVPHY_PLL_TYPE_CPLL,   XVPHY_PLL_TYPE_CPLL,
		  XVPHY_CHANNEL_ID_CHA,     XVPHY_CHANNEL_ID_CHA,     0x06,
		  XVPHY_DP_LINK_RATE_HZ_162GBPS,      DP159_FORWARDED_CLK,
		  DP159_FORWARDED_CLK,        81000000,            81000000        },
  {   2,     XVPHY_PLL_TYPE_CPLL,   XVPHY_PLL_TYPE_CPLL,
		  XVPHY_CHANNEL_ID_CHA,     XVPHY_CHANNEL_ID_CHA,     0x0A,
		  XVPHY_DP_LINK_RATE_HZ_270GBPS,      DP159_FORWARDED_CLK,
		  DP159_FORWARDED_CLK,        135000000,           135000000        },
  {   3,     XVPHY_PLL_TYPE_CPLL,   XVPHY_PLL_TYPE_CPLL,
		  XVPHY_CHANNEL_ID_CHA,     XVPHY_CHANNEL_ID_CHA,     0x14,
		  XVPHY_DP_LINK_RATE_HZ_540GBPS,      DP159_FORWARDED_CLK,
		  DP159_FORWARDED_CLK,        270000000,           270000000        },
  {   4,     XVPHY_PLL_TYPE_CPLL,   XVPHY_PLL_TYPE_CPLL,
		  XVPHY_CHANNEL_ID_CHA,     XVPHY_CHANNEL_ID_CHA,     0x06,
		  XVPHY_DP_LINK_RATE_HZ_162GBPS,      ONBOARD_REF_CLK,
		  ONBOARD_REF_CLK,            135000000,           135000000        },
  {   5,     XVPHY_PLL_TYPE_CPLL,   XVPHY_PLL_TYPE_CPLL,
		  XVPHY_CHANNEL_ID_CHA,     XVPHY_CHANNEL_ID_CHA,     0x0A,
		  XVPHY_DP_LINK_RATE_HZ_270GBPS,      ONBOARD_REF_CLK,
		  ONBOARD_REF_CLK,            135000000,           135000000        },
  {   6,     XVPHY_PLL_TYPE_CPLL,   XVPHY_PLL_TYPE_CPLL,
		  XVPHY_CHANNEL_ID_CHA,     XVPHY_CHANNEL_ID_CHA,     0x14,
		  XVPHY_DP_LINK_RATE_HZ_540GBPS,      ONBOARD_REF_CLK,
		  ONBOARD_REF_CLK,            135000000,           135000000        },

};


void PLLRefClkSel (XVphy *InstancePtr, u8 link_rate);
u32 PHY_Configuration_Rx(XVphy *InstancePtr,
							XVphy_User_Config PHY_User_Config_Table);
u32 PHY_Configuration_Tx(XVphy *InstancePtr,
							XVphy_User_Config PHY_User_Config_Table);
void Dppt_Tx_SetRefClocks(u8 DPLinkRate_Value, u8 is_TX_CPLL);
void Two_byte_set (XVphy *InstancePtr, u8 Tx_to_two_byte, u8 Rx_to_two_byte);
void lmk();

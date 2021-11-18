
/* mdaq_can.h -- CAN driver for MicroDAQ device
 *
 * Copyright (C) 2020 Embedded Solutions
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license.  See the LICENSE file for details.
 */

#ifndef MDAQ_CAN_H
#define MDAQ_CAN_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* CAN channel IDs */
enum mdaq_can_ids
{
    CAN1,
    CAN2,
    CAN3,
    CAN4,
    CAN5,
    CAN6,
    CAN7,
    CAN8
};

#define RXFIFO0     (0u)
#define RXFIFO1     (1u)

#define CAN_DLC_0B   0x00000000
#define CAN_DLC_1B   0x00000001
#define CAN_DLC_2B   0x00000002
#define CAN_DLC_3B   0x00000003
#define CAN_DLC_4B   0x00000004
#define CAN_DLC_5B   0x00000005
#define CAN_DLC_6B   0x00000006
#define CAN_DLC_7B   0x00000007
#define CAN_DLC_8B   0x00000008
#define CAN_DLC_12B  0x00000009
#define CAN_DLC_16B  0x0000000A
#define CAN_DLC_20B  0x0000000B
#define CAN_DLC_24B  0x0000000C
#define CAN_DLC_32B  0x0000000D
#define CAN_DLC_48B  0x0000000E
#define CAN_DLC_64B  0x0000000F

#define B10000       (10000)  
#define B20000       (20000)  
#define B25000       (25000)  
#define B40000       (40000)  
#define B50000       (50000)  
#define B100000      (100000) 
#define B200000      (200000) 
#define B250000      (250000) 
#define B400000      (400000) 
#define B500000      (500000) 
#define B800000      (800000) 
#define B1000000     (1000000)
#define B2000000     (2000000)
#define B2500000     (2500000)
#define B4000000     (4000000)
#define B5000000     (5000000)
#define B8000000     (8000000)

/**
 * @brief Struct containing the CAN interrupt bit field
 */
typedef struct
{
    union
    {
        //! @brief Full register as single 32-bit word
        uint32_t word;
        struct
        {
            //! @brief IR[0] RF0N: Rx FIFO 0 new message
            uint8_t RF0N : 1;

            //! @brief IR[1] RF0W: Rx FIFO 0 watermark reached
            uint8_t RF0W : 1;

            //! @brief IR[2] RF0F: Rx FIFO 0 full
            uint8_t RF0F : 1;

            //! @brief IR[3] RF0L: Rx FIFO 0 message lost
            uint8_t RF0L : 1;

            //! @brief IR[4] RF1N: Rx FIFO 1 new message
            uint8_t RF1N : 1;

            //! @brief IR[5]  RF1W: RX FIFO 1 watermark reached
            uint8_t RF1W : 1;

            //! @brief IR[6] RF1F: Rx FIFO 1 full
            uint8_t RF1F : 1;

            //! @brief IR[7] RF1L: Rx FIFO 1 message lost
            uint8_t RF1L : 1;

            //! @brief IR[8] HPM: High priority message
            uint8_t HPM : 1;

            //! @brief IR[9] TC: Transmission completed
            uint8_t TC : 1;

            //! @brief IR[10] TCF: Transmission cancellation finished
            uint8_t TCF : 1;

            //! @brief IR[11] TFE: Tx FIFO Empty
            uint8_t TFE : 1;

            //! @brief IR[12] TEFN: Tx Event FIFO new entry
            uint8_t TEFN : 1;

            //! @brief IR[13] TEFW: Tx Event FIFO water mark reached
            uint8_t TEFW : 1;

            //! @brief IR[14] TEFF: Tx Event FIFO full
            uint8_t TEFF : 1;

            //! @brief IR[15] TEFL: Tx Event FIFO element lost
            uint8_t TEFL : 1;

            //! @brief IR[16] TSW: Timestamp wrapped around
            uint8_t TSW : 1;

            //! @brief IR[17] MRAF: Message RAM access failure
            uint8_t MRAF : 1;

            //! @brief IR[18] TOO: Time out occurred
            uint8_t TOO : 1;

            //! @brief IR[19] DRX: Message stored to dedicated RX buffer
            uint8_t DRX : 1;

            //! @brief IR[20] BEC: MRAM Bit error corrected
            uint8_t BEC : 1;

            //! @brief IR[21] BEU: MRAM Bit error uncorrected
            uint8_t BEU : 1;

            //! @brief IR[22] ELO: Error logging overflow
            uint8_t ELO : 1;

            //! @brief IR[23] EP: Error_passive status changed
            uint8_t EP : 1;

            //! @brief IR[24] EW: Error_warning status changed
            uint8_t EW : 1;

            //! @brief IR[25] BO: Bus_off status changed
            uint8_t BO : 1;

            //! @brief IR[26] WDI: MRAM Watchdog Interrupt
            uint8_t WDI : 1;

            //! @brief IR[27] PEA Protocol Error in arbitration phase (nominal bit time used)
            uint8_t PEA : 1;

            //! @brief IR[28] PED: Protocol error in data phase (data bit time is used)
            uint8_t PED : 1;

            //! @brief IR[29] ARA: Access to reserved address
            uint8_t ARA : 1;

            //! @brief IR[30:31] Reserved, not writable
            uint8_t reserved : 2;
        };
    };
} can_int_state_t;


/**
 * @brief Struct containing the MCAN interrupt enable bit field
 */
typedef struct
{
    union
    {
        //! Full register as single 32-bit word
        uint32_t word;
        struct
        {
            //! @brief IE[0] RF0NE: Rx FIFO 0 new message
            uint8_t RF0NE : 1;

            //! @brief IE[1] RF0WE: Rx FIFO 0 watermark reached
            uint8_t RF0WE : 1;

            //! @brief IE[2] RF0FE: Rx FIFO 0 full
            uint8_t RF0FE : 1;

            //! @brief IE[3] RF0LE: Rx FIFO 0 message lost
            uint8_t RF0LE : 1;

            //! @brief IE[4] RF1NE: Rx FIFO 1 new message
            uint8_t RF1NE : 1;

            //! @brief IE[5]  RF1WE: RX FIFO 1 watermark reached
            uint8_t RF1WE : 1;

            //! @brief IE[6] RF1FE: Rx FIFO 1 full
            uint8_t RF1FE : 1;

            //! @brief IE[7] RF1LE: Rx FIFO 1 message lost
            uint8_t RF1LE : 1;

            //! @brief IE[8] HPME: High priority message
            uint8_t HPME : 1;

            //! @brief IE[9] TCE: Transmission completed
            uint8_t TCE : 1;

            //! @brief IE[10] TCFE: Transmission cancellation finished
            uint8_t TCFE : 1;

            //! @brief IE[11] TFEE: Tx FIFO Empty
            uint8_t TFEE : 1;

            //! @brief IE[12] TEFNE: Tx Event FIFO new entry
            uint8_t TEFNE : 1;

            //! @brief IE[13] TEFWE: Tx Event FIFO watermark reached
            uint8_t TEFWE : 1;

            //! @brief IE[14] TEFFE: Tx Event FIFO full
            uint8_t TEFFE : 1;

            //! @brief IE[15] TEFLE: Tx Event FIFO element lost
            uint8_t TEFLE : 1;

            //! @brief IE[16] TSWE: Timestamp wraparound
            uint8_t TSWE : 1;

            //! @brief IE[17] MRAFE: Message RAM access failure
            uint8_t MRAFE : 1;

            //! @brief IE[18] TOOE: Time out occured
            uint8_t TOOE : 1;

            //! @brief IE[19] DRXE: Message stored to dedicated RX buffer
            uint8_t DRXE : 1;

            //! @brief IE[20] BECE: MRAM Bit error corrected
            uint8_t BECE : 1;

            //! @brief IE[21] BEUE: MRAM Bit error uncorrected
            uint8_t BEUE : 1;

            //! @brief IE[22] ELOE: Error logging overflow
            uint8_t ELOE : 1;

            //! @brief IE[23] EPE: Error_passive status changed
            uint8_t EPE : 1;

            //! @brief IE[24] EWE: Error_warning status changed
            uint8_t EWE : 1;

            //! @brief IE[25] BOE: Bus_off status changed
            uint8_t BOE : 1;

            //! @brief IE[26] WDIE: MRAM Watchdog Interrupt
            uint8_t WDIE : 1;

            //! @brief IE[27] PEAE Protocol Error in arbitration phase (nominal bit time used)
            uint8_t PEAE : 1;

            //! @brief IE[28] PEDE: Protocol error in data phase (data bit time is used)
            uint8_t PEDE : 1;

            //! @brief IE[29] ARAE: Access to reserved address
            uint8_t ARAE : 1;

            //! @brief IE[30:31] Reserved, not writable
            uint8_t reserved : 2;
        };
    };
} can_int_enable_flags_t;


/**
 * @brief CAN message header
 */
typedef struct __attribute__((__packed__))
{
    //! @brief CAN ID received
    uint32_t ID : 29;

    //! @brief Remote Transmission Request flag
    uint8_t RTR : 1;

    //! @brief Extended Identifier flag
    uint8_t XTD : 1;

    //! @brief Error state indicator flag
    uint8_t ESI : 1;

    //! @brief Receive time stamp
    uint16_t RXTS : 16;

    //! @brief Data length code
    uint8_t DLC : 4;

    //! @brief Bit rate switch used flag
    uint8_t BRS : 1;

    //! @brief CAN FD Format flag
    uint8_t FDF : 1;

    //! @brief Reserved (0)
    uint8_t reserved : 2;

    //! @brief Filter index that this message matched
    uint8_t FIDX : 7;

    //! @brief Accepted non matching frame flag
    uint8_t ANMF : 1;

} can_rx_header_t;


/**
 * @brief CAN message header for transmitted messages
 */
typedef struct __attribute__((__packed__))
{
   //! @brief CAN ID to send
    uint32_t ID : 29;

   //! @brief Remote Transmission Request flag
    uint8_t RTR : 1;

   //! @brief Extended Identifier flag
    uint8_t XTD : 1;

   //! @brief Error state indicator flag
    uint8_t ESI : 1;

   //! @brief Data length code
    uint8_t DLC : 4;

   //! @brief Bit rate switch used flag
    uint8_t BRS : 1;

   //! @brief CAN FD Format flag
    uint8_t FDF : 1;

   //! @brief Reserved
    uint8_t reserved : 1;

   //! @brief Event FIFO Control flag, to store tx events or not
    uint8_t EFC : 1;

   //! @brief Message Marker, used if @c EFC is set to 1
    uint8_t MM : 8;

}can_tx_header_t;


typedef struct
{
    can_tx_header_t     header;
    uint8_t             data[64];
}canfd_tx_frame_t;

typedef struct
{
    can_rx_header_t     header;
    uint8_t             data[64];
}canfd_rx_frame_t;

void mdaq_can_init(void);

uint8_t mdaq_can_open(uint8_t can_channel, uint32_t baud_rate, uint32_t baud_rate_data);
void mdaq_can_close(uint8_t can_channel);

void mdaq_can_read_int_flags(uint8_t can_channel, can_int_state_t *ir);
void mdaq_can_clear_int_flags(uint8_t can_channel, can_int_state_t *ir);
void mdaq_can_clear_all_int_flags(uint8_t can_channel);
void mdaq_can_enable_int_flag(uint8_t can_channel, can_int_enable_flags_t *ie);

uint8_t mdaq_can_is_rx_fifo_empty(uint8_t can_channels, uint8_t fifo);
uint8_t mdaq_can_read_fifo(uint8_t can_channel, uint8_t fifo, can_rx_header_t *header, uint8_t data[]);
uint8_t mdaq_can_read_buffer(uint8_t can_channel, uint8_t buf_index, can_rx_header_t *header, uint8_t data[]);

uint32_t mdaq_can_write_buffer(uint8_t can_channel, uint8_t buf_index, can_tx_header_t *header, uint8_t data[]);
bool mdaq_can_transmit_buffer(uint8_t can_channel, uint8_t buf_index);

void mdaq_can_write_mcan_reg(uint8_t can_channel, uint16_t addr, uint32_t data);
uint32_t mdaq_can_read_mcan_reg(uint8_t can_channel, uint16_t addr);

bool mdaq_can_is_tx_fifo_full(uint8_t can_channel);

#if 0 /* TODO: add filter support */
bool mdaq_can_write_sid_filter(uint8_t can_channel, uint8_t filter_index, can_sid_filter_t *filter);
bool mdaq_can_read_sid_filter(uint8_t can_channel, uint8_t filter_index, uint8_t filter_index, can_sid_filter_t *filter);
bool mdaq_can_write_xid_filter(uint8_t can_channel, uint8_t filter_index, can_xid_filter_t *filter);
#endif

void mdaq_can_enable_termination(uint8_t can_channel, uint8_t state);

uint8_t mdaq_can_dlc2bytes(uint8_t dlc);


#ifdef __cplusplus
}
#endif
#endif /* MDAQ_CAN_H */




// Microchip ENC28J60 Ethernet Interface Driver
// Author: Pascal Stang
// Modified by: Guido Socher
// Copyright: GPL V2
//
// This driver provides initialization and transmit/receive
// functions for the Microchip ENC28J60 10Mb Ethernet Controller and PHY.
// This chip is novel in that it is a full MAC+PHY interface all in a 28-pin
// chip, using an SPI interface to the host processor.
//
// 2010-05-20 <jc@wippler.nl>
/** @file */

#ifndef ENC28J60_H
#define ENC28J60_H

/** This class provide low-level interfacing with the ENC28J60 network interface. This is used by the EtherCard class and not intended for use by (normal) end users. */
class ENC28J60 {
public:
    static uint8_t buffer[]; //!< Data buffer (shared by recieve and transmit)
    static uint16_t bufferSize; //!< Size of data buffer
    static bool broadcast_enabled; //!< True if broadcasts enabled (used to allow temporary disable of broadcast for DHCP or other internal functions)
    static bool promiscuous_enabled; //!< True if promiscuous mode enabled (used to allow temporary disable of promiscuous mode)

    static uint8_t* tcpOffset () { return buffer + 0x36; } //!< Pointer to the start of TCP payload

    /**   @brief  Initialise SPI interface
    *     @note   Configures Arduino pins as input / output, etc.
    */
    static void initSPI ();

    /**   @brief  Initialise network interface
    *     @param  size Size of data buffer
    *     @param  macaddr Pointer to 6 byte hardware (MAC) address
    *     @param  csPin Arduino pin used for chip select (enable network interface SPI bus). Default = 8
    *     @return <i>uint8_t</i> ENC28J60 firmware version or zero on failure.
    */
    static uint8_t initialize (const uint16_t size, const uint8_t* macaddr,
                               uint8_t csPin = 8);

    /**   @brief  Check if network link is connected
    *     @return <i>bool</i> True if link is up
    */
    static bool isLinkUp ();

    /**   @brief  Sends data to network interface
    *     @param  len Size of data to send
    *     @note   Data buffer is shared by recieve and transmit functions
    */
    static void packetSend (uint16_t len);

    /**   @brief  Copy recieved packets to data buffer
    *     @return <i>uint16_t</i> Size of recieved data
    *     @note   Data buffer is shared by recieve and transmit functions
    */
    static uint16_t packetReceive ();

    /**   @brief  Copy data from ENC28J60 memory
    *     @param  page Data page of memory
    *     @param  data Pointer to buffer to copy data to
    */
    static void copyout (uint8_t page, const uint8_t* data);

    /**   @brief  Copy data to ENC28J60 memory
    *     @param  page Data page of memory
    *     @param  data Pointer to buffer to copy data from
    */
    static void copyin (uint8_t page, uint8_t* data);

    /**   @brief  Get single byte of data from ENC28J60 memory
    *     @param  page Data page of memory
    *     @param  off Offset of data within page
    *     @return Data value
    */
    static uint8_t peekin (uint8_t page, uint8_t off);

    /**   @brief  Put ENC28J60 in sleep mode
    */
    static void powerDown();  // contrib by Alex M.

    /**   @brief  Wake ENC28J60 from sleep mode
    */
    static void powerUp();    // contrib by Alex M.

    /**   @brief  Enable reception of broadcast messages
    *     @param  temporary Set true to temporarily enable broadcast
    *     @note   This will increase load on recieved data handling
    */
    static void enableBroadcast(bool temporary = false);

    /**   @brief  Disable reception of broadcast messages
    *     @param  temporary Set true to only disable if temporarily enabled
    *     @note   This will reduce load on recieved data handling
    */
    static void disableBroadcast(bool temporary = false);

    /**   @brief  Enables reception of mulitcast messages
    *     @note   This will increase load on recieved data handling
    */
    static void enableMulticast ();
    
    /**   @brief  Enables reception of all messages
    *     @param  temporary Set true to temporarily enable promiscuous
    *     @note   This will increase load significantly on recieved data handling
    *     @note   All messages will be accepted, even messages with destination MAC other than own
    *     @note   Messages with invalid CRC checksum will still be rejected
    */
    static void enablePromiscuous (bool temporary = false);
    
    /**   @brief  Disable reception of all messages and go back to default mode
    *     @param  temporary Set true to only disable if temporarily enabled
    *     @note   This will reduce load on recieved data handling
    *     @note   In this mode only unicast and broadcast messages will be received
    */
    static void disablePromiscuous(bool temporary = false);

    /**   @brief  Disable reception of mulitcast messages
    *     @note   This will reduce load on recieved data handling
    */
    static void disableMulticast();

    /**   @brief  Reset and fully initialise ENC28J60
    *     @param  csPin Arduino pin used for chip select (enable SPI bus)
    *     @return <i>uint8_t</i> 0 on failure
    */
    static uint8_t doBIST(uint8_t csPin = 8);
};

typedef ENC28J60 Ethernet; //!< Define alias Ethernet for ENC28J60


/** Workaround for Errata 13.
*   The transmission hardware may drop some packets because it thinks a late collision
*   occurred (which should never happen if all cable length etc. are ok). If setting
*   this to 1 these packages will be retried a fixed number of times. Costs about 150bytes
*   of flash.
*/
#define ETHERCARD_RETRY_LATECOLLISIONS 0

/** Enable pipelining of packet transmissions.
*   If enabled the packetSend function will not block/wait until the packet is actually
*   transmitted; but instead this wait is shifted to the next time that packetSend is
*   called. This gives higher performance; however in combination with 
*   ETHERCARD_RETRY_LATECOLLISIONS this may lead to problems because a packet whose
*   transmission fails because the ENC-chip thinks that it is a late collision will
*   not be retried until the next call to packetSend.
*/
#define ETHERCARD_SEND_PIPELINING 0
#endif

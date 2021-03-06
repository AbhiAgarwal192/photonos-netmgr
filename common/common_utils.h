/*
 * Copyright © 2016-2018 VMware, Inc.  All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the “License”); you may not
 * use this file except in compliance with the License.  You may obtain a copy
 * of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an “AS IS” BASIS, without
 * warranties or conditions of any kind, EITHER EXPRESS OR IMPLIED.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */

#ifndef __COMMON_UTILS_H__
#define __COMMON_UTILS_H__

#define IS_VALID_INTERFACE_NAME(_pstr) \
    ((_pstr) && (*_pstr) && (strnlen(_pstr, IFNAMSIZ) < IFNAMSIZ))

typedef struct _NETLINK_MESSAGE
{
    struct _NETLINK_MESSAGE *pNext;
    uint16_t msgType;
    int msgLen;
    void *pMsg;
} NETLINK_MESSAGE, *PNET_NETLINK_MESSAGE;

uint32_t
is_ipv4_addr(const char *pszIpAddr);

uint32_t
is_ipv6_addr(const char *pszIpAddr);

uint32_t
is_ipv6_link_local_addr(const char *pszIpAddr);

uint32_t
is_ipv6_autoconf_addr(const char *pszIpAddr, const char *pszMacAddr);

uint32_t
flush_interface_ipaddr(
    const char *pszInterfaceName
);

uint32_t
get_prefix_from_netmask(
    struct sockaddr *sin,
    uint8_t *prefix
);

uint32_t
open_netlink_socket(
    uint32_t netLinkGroup,
    int *pSockFd
);

uint32_t
handle_netlink_event(
    const int sockFd,
    PNET_NETLINK_MESSAGE *ppNetLinkMsgList
);

void
free_netlink_message_list(
    NETLINK_MESSAGE *pNetLinkMsg
);

#endif /* __COMMON_UTILS_H__ */

/*
*   TcpServerNetworkManager manages server-side TCP socket communication
*
*   Author: Fu Qiao 
*   Email:  fqiao@protonmail.com
*
*/


#ifndef __TCP_SERVER_NETWORK_MANAGER_H__
#define __TCP_SERVER_NETWORK_MANAGER_H__

#include "NetworkServiceManager.h"
#include <atomic>

namespace sobertalk {

class TcpServerNetworkManager : public NetworkServiceManager {

using TcpSocket = network::TcpSocket;
using NetworkRequest = common::NetworkRequest;

public:
  TcpServerNetworkManager(uint16_t port, std::shared_ptr<SocketMessageQueue> queue_In, std::shared_ptr<SocketMessageQueue> queue_Out);

  ~TcpServerNetworkManager();

  void HandleRequestIn() override;

  void HandleRequestOut() override;

  void Start() override;

private:
  void Init() override;

  TcpServerNetworkManager(const TcpServerNetworkManager& other);
  TcpServerNetworkManager& operator=(const TcpServerNetworkManager& other);

  std::unique_ptr<TcpSocket> _listener {nullptr};
  uint16_t _port;

};
}

#endif
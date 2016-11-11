// Copyright (c) 2014-2016, The Singularity Project
// 
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
// 
// 1. Redistributions of source code must retain the above copyright notice, this list of
//    conditions and the following disclaimer.
// 
// 2. Redistributions in binary form must reproduce the above copyright notice, this list
//    of conditions and the following disclaimer in the documentation and/or other
//    materials provided with the distribution.
// 
// 3. Neither the name of the copyright holder nor the names of its contributors may be
//    used to endorse or promote products derived from this software without specific
//    prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
// THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#pragma once

#include "string_tools.h"
#include "net/http_client.h"

namespace tools {

class t_http_connection {
private:
  epee::net_utils::http::http_simple_client * mp_http_client;
  bool m_ok;
public:
  static unsigned int const TIMEOUT = 200000;

  t_http_connection(
      epee::net_utils::http::http_simple_client * p_http_client
    , uint32_t ip
    , uint16_t port
    )
    : mp_http_client(p_http_client)
    , m_ok(false)
  {
    // TODO fix http client so that it accepts properly typed arguments
    std::string ip_str = epee::string_tools::get_ip_string_from_int32(ip);
    std::string port_str = boost::lexical_cast<std::string>(port);
    m_ok = mp_http_client->connect(ip_str, port_str, TIMEOUT);
  }

  ~t_http_connection()
  {
    if (m_ok)
    {
      mp_http_client->disconnect();
    }
  }

  bool is_open() const
  {
    return m_ok;
  }
}; // class t_http_connection

} // namespace tools

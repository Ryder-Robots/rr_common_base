// Copyright (c) 2025 Ryder Robots
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef RR_NODE_PLUGIN_IFACE_HPP
#define RR_NODE_PLUGIN_IFACE_HPP

#include <functional>
#include <memory>


namespace rrobots
{
    namespace interfaces
    {
        template<typename MessageT>
        class InboundComT : public rrobots::interfaces::InboundComT<MessageT>
        {
          public:
            using MessageType = MessageT;
            using CallbackType = std::function<void(const MessageT &)>;

            virtual ~InboundComT() = default;

            // Method to configure the inbound topic or source
            virtual void on_activate(const std::string &topic_name, size_t queue_size) = 0;

            // Registers the node subscription callback to be called on inbound messages
            virtual void set_callback(CallbackType cb) = 0;

            // Starts listening or subscribing to inbound data source
            virtual void start() = 0;

            // Stops listening or unsubscribing
            virtual void stop() = 0;
        };
    } // namespace plugins
} // namespace rrobots

#endif // RR_NODE_PLUGIN_IFACE_HPP
#include "message_bus.h"

#include <QList>
#include <QMap>
#include <QString>
#include <functional>
#include <memory>

#include "message.h"

// 注册消息类型的订阅者
void MessageBus::Subscribe(const Message& message_type, std::function<void()> handler)
{
	m_voidVoidsubscribers[message_type].push_back(handler);
}
void MessageBus::Publish(const Message& message_type)
{
	// 查找该类型的订阅者，并触发他们的回调
	if (m_voidVoidsubscribers.find(message_type) != m_voidVoidsubscribers.end())
	{
		for (auto& handler : m_voidVoidsubscribers[message_type])
		{
			handler();  // 执行订阅者的回调
		}
	}
}

// 注册消息类型的订阅者
void MessageBus::Subscribe(const Message& message_type, std::function<void(int)> handler)
{
	m_voidIntsubscribers[message_type].push_back(handler);
}
void MessageBus::Publish(const Message& message_type, const int& data)
{
	if (m_voidIntsubscribers.find(message_type) != m_voidIntsubscribers.end())
	{
		for (auto& handler : m_voidIntsubscribers[message_type])
		{
			handler(data);  // 执行订阅者的回调
		}
	}
}

// 注册消息类型的订阅者
void MessageBus::Subscribe(const Message& message_type, std::function<void(int, int)> handler)
{
	m_voidIntIntsubscribers[message_type].push_back(handler);
}
void MessageBus::Publish(const Message& message_type, const int& data1, const int& data2)
{
	if (m_voidIntIntsubscribers.find(message_type) != m_voidIntIntsubscribers.end())
	{
		for (auto& handler : m_voidIntIntsubscribers[message_type])
		{
			handler(data1, data2);  // 执行订阅者的回调
		}
	}
}

// 注册消息类型的订阅者
void MessageBus::Subscribe(const Message& message_type, std::function<void(const QString&)> handler)
{
	m_voidQStringSubscribers[message_type].push_back(handler);
}
void MessageBus::Publish(const Message& message_type, const QString& data)
{
	if (m_voidQStringSubscribers.find(message_type) != m_voidQStringSubscribers.end())
	{
		for (auto& handler : m_voidQStringSubscribers[message_type])
		{
			handler(data);  // 执行订阅者的回调
		}
	}
}

// 注册消息类型的订阅者
void MessageBus::Subscribe(const Message& message_type, std::function<void(const QStringList&)> handler)
{
	m_voidQStringListSubscribers[message_type].push_back(handler);
}
void MessageBus::Publish(const Message& message_type, const QStringList& data)
{
	if (m_voidQStringListSubscribers.find(message_type) != m_voidQStringListSubscribers.end())
	{
		for (auto& handler : m_voidQStringListSubscribers[message_type])
		{
			handler(data);  // 执行订阅者的回调
		}
	}
}

// 注册消息类型的订阅者
void MessageBus::Subscribe(const Message& message_type, std::function<void(OnTextEdit*)> handler)
{
	m_voidCustomTextEditSubscribers[message_type].push_back(handler);
}
void MessageBus::Publish(const Message& message_type, OnTextEdit* data)
{
	if (m_voidCustomTextEditSubscribers.find(message_type) != m_voidCustomTextEditSubscribers.end())
	{
		for (auto& handler : m_voidCustomTextEditSubscribers[message_type])
		{
			handler(data);  // 执行订阅者的回调
		}
	}
}
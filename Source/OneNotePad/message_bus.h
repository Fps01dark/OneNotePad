#pragma once

#include <QList>
#include <QMap>
#include <QString>
#include <functional>
#include <memory>

class OnTextEdit;
enum Message;

class MessageBus
{
public:
	// 注册消息类型的订阅者
	void Subscribe(const Message& message_type, std::function<void()> handler);
	void Publish(const Message& message_type);

	// 注册消息类型的订阅者
	void Subscribe(const Message& message_type, std::function<void(int)> handler);
	void Publish(const Message& message_type, const int& data);

	// 注册消息类型的订阅者
	void Subscribe(const Message& message_type, std::function<void(int, int)> handler);
	void Publish(const Message& message_type, const int& data1, const int& data2);

	// 注册消息类型的订阅者
	void Subscribe(const Message& message_type, std::function<void(const QString&)> handler);
	void Publish(const Message& message_type, const QString& data);

	// 注册消息类型的订阅者
	void Subscribe(const Message& message_type, std::function<void(const QStringList&)> handler);
	void Publish(const Message& message_type, const QStringList& data);

	// 注册消息类型的订阅者
	void Subscribe(const Message& message_type, std::function<void(OnTextEdit*)> handler);
	void Publish(const Message& message_type, OnTextEdit* data);

private:
	// 存储每种消息类型对应的所有订阅者回调
	QMap<Message, QList<std::function<void()>>> m_voidVoidsubscribers;
	QMap<Message, QList<std::function<void(bool)>>> m_voidBoolsubscribers;
	QMap<Message, QList<std::function<void(int)>>> m_voidIntsubscribers;
	QMap<Message, QList<std::function<void(int, int)>>> m_voidIntIntsubscribers;
	QMap<Message, QList<std::function<void(const QString&)>>> m_voidQStringSubscribers;
	QMap<Message, QList<std::function<void(const QStringList&)>>> m_voidQStringListSubscribers;
	QMap<Message, QList<std::function<void(OnTextEdit*)>>> m_voidCustomTextEditSubscribers;
};
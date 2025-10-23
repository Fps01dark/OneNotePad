#include "on_status_bar.h"

#include "message_bus.h"
#include "message.h"
#include "on_text_edit.h"
#include "status_label.h"

OnStatusBar::OnStatusBar(std::shared_ptr<MessageBus> message_bus, QWidget* parent)
	:m_messageBus(message_bus), QStatusBar(parent)
{
	InitUi();
	InitValue();
	InitConnect();
}

OnStatusBar::~OnStatusBar()
{
}

void OnStatusBar::Refresh(OnTextEdit* editor)
{
}

void OnStatusBar::InitUi()
{
	m_docType = new StatusLabel();
	addWidget(m_docType, 1);

	m_docSize = new StatusLabel(200);
	addPermanentWidget(m_docSize, 0);

	m_docPos = new StatusLabel(250);
	addPermanentWidget(m_docPos, 0);

	m_eolFormat = new StatusLabel(100);
	addPermanentWidget(m_eolFormat, 0);

	m_unicodeType = new StatusLabel(125);
	addPermanentWidget(m_unicodeType, 0);

	m_overType = new StatusLabel(25);
	addPermanentWidget(m_overType, 0);
}

void OnStatusBar::InitValue()
{
	m_messageBus->Subscribe(Message::UpdateStatusBar, [this](OnTextEdit* editor)
		{
			qDebug() << "This file is " << __FILE__ << " on line " << __LINE__;
			qDebug(Q_FUNC_INFO);

			m_messageBus->Publish(Message::UpdateLanguage, editor);
			m_messageBus->Publish(Message::UpdateDocumentSize, editor);
			m_messageBus->Publish(Message::UpdateSelectionInfo, editor);
			m_messageBus->Publish(Message::UpdateEol, editor);
			m_messageBus->Publish(Message::UpdateEncoding, editor);
			m_messageBus->Publish(Message::UpdateOverType, editor);
		});

	m_messageBus->Subscribe(Message::UpdateLanguage, [this](OnTextEdit* editor)
		{
			// TODO:暂时语言只有None
			m_docType->setText("Normal Text File");
		});
	m_messageBus->Subscribe(Message::UpdateDocumentSize, [this](OnTextEdit* editor)
		{
			qDebug() << "This file is " << __FILE__ << " on line " << __LINE__;
			qDebug(Q_FUNC_INFO);

			QString size_text = tr("Length: %L1    Lines: %L2").arg(editor->length()).arg(editor->lineCount());
			m_docSize->setText(size_text);
		});
	m_messageBus->Subscribe(Message::UpdateSelectionInfo, [this](OnTextEdit* editor)
		{
			qDebug() << "This file is " << __FILE__ << " on line " << __LINE__;
			qDebug(Q_FUNC_INFO);

			const sptr_t pos = editor->currentPos();
			QString selection_text;
			if (editor->selectionEnd() == editor->selectionStart())
			{
				// 未选择
				selection_text = tr("Pos: %1").arg(pos);
			}
			else
			{
				// 选择
				if (editor->selections() > 1)
				{
					// TODO:多选 3x4->6
					selection_text = tr("Sel: N/A");
				}
				else
				{
					// 单选
					sptr_t start = editor->selectionStart();
					sptr_t end = editor->selectionEnd();
					sptr_t lines = editor->lineFromPosition(end) - editor->lineFromPosition(start);

					if (end > start)
						lines++;

					selection_text = tr("Sel: %L1 | %L2").arg(editor->countCharacters(start, end)).arg(lines);
				}
			}

			QString position_text = tr("Ln: %L1    Col: %L2    ").arg(editor->lineFromPosition(pos) + 1).arg(editor->column(pos) + 1);
			m_docPos->setText(position_text + selection_text);
		});
	m_messageBus->Subscribe(Message::UpdateEol, [this](OnTextEdit* editor)
		{
			qDebug() << "This file is " << __FILE__ << " on line " << __LINE__;
			qDebug(Q_FUNC_INFO);

			switch (editor->eOLMode())
			{
			case SC_EOL_CR:
				m_eolFormat->setText(tr("Macintosh (CR)"));
				break;
			case SC_EOL_CRLF:
				m_eolFormat->setText(tr("Windows (CR LF)"));
				break;
			case SC_EOL_LF:
				m_eolFormat->setText(tr("Unix (LF)"));
				break;
			}
		});
	m_messageBus->Subscribe(Message::UpdateEncoding, [this](OnTextEdit* editor)
		{
			switch (editor->codePage())
			{
			case 0:
				m_unicodeType->setText(tr("ANSI"));
				break;
			case SC_CP_UTF8:
				m_unicodeType->setText(tr("UTF-8"));
				break;
			default:
				m_unicodeType->setText(QString::number(editor->codePage()));
				break;
			}
		});
	m_messageBus->Subscribe(Message::UpdateOverType, [this](OnTextEdit* editor)
		{
			bool overtype = editor->overtype();
			if (overtype)
			{
				m_overType->setText(tr("OVR"));
			}
			else
			{
				m_overType->setText(tr("INS"));
			}
		});
}

void OnStatusBar::InitConnect()
{
}
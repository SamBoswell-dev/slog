#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <sstream>

/// FORMAT API
/// 
/// %^N		// name of logger
/// %^L		// Level of log
/// %^M		// Message
/// %^V		// Value as Text
/// %^H		// Value as Hex
/// %^B		// Value as Binary
/// 
/// 
/// [%^N] %^L: %^M | %^V
/// 

class SLog {
private:
	std::string m_LoggerName;
	static std::string m_Format;
	static std::string m_FormatEx;

	enum class LOGLEVEL {
		TRACE,
		WARNING
	};

public:
	SLog(const std::string& loggerName) : m_LoggerName(loggerName) {};
	
	static void SetFormat(const std::string& format) { m_Format = format; }
	static void SetFormatEx(const std::string& format) { m_FormatEx = format; }
	void Init();

	void Trace(const std::string& message)
	{
		std::stringstream output;
		ParseMessage(LOGLEVEL::TRACE, output, message);

		std::cout << output.str();
	}

	template<typename T>
	void Trace(const std::string& message, T arg)
	{
		std::stringstream output;
		ParseMessage(LOGLEVEL::TRACE, output, message, arg);

		std::cout << output.str();

	}

private:

	void ParseMessage(LOGLEVEL level, std::stringstream& stream, const std::string& message)
	{
		std::string format = m_Format;

		size_t position = m_Format.find_first_of("%^");
		std::string temp = m_Format.substr(0, position);
		stream << temp;

		while (position < 100000000)
		{
			format = format.erase(0, position + 2);

			switch (format[0])
			{
			case 'N':
				stream << m_LoggerName;
				break;
			case 'L':
				switch (level)
				{
				case LOGLEVEL::TRACE:
					stream << "TRACE";
					break;
				case LOGLEVEL::WARNING:
					stream << "WARNING";
					break;
				}
				break;
			case 'M':
				stream << message;
				break;
			}

			format = format.erase(0, 1);

			position = format.find_first_of("%^");
			temp = format.substr(0, position);
			stream << temp;
		}
		stream << "\n";
	}

	template<typename T>
	void ParseMessage(LOGLEVEL level, std::stringstream& stream, const std::string& message, T arg)
	{
		std::string format = m_FormatEx;

		size_t position = m_FormatEx.find_first_of("%^");
		std::string temp = m_FormatEx.substr(0, position);
		stream << temp;

		while (position < 100000000)
		{
			format = format.erase(0, position + 2);

			switch (format[0])
			{
			case 'N':
				stream << m_LoggerName;
				break;
			case 'L':
				switch (level)
				{
				case LOGLEVEL::TRACE:
					stream << "TRACE";
					break;
				case LOGLEVEL::WARNING:
					stream << "WARNING";
					break;
				}
				break;
			case 'M':
				stream << message;
				break;
			case 'V':
				stream << arg;
				break;
		}

			format = format.erase(0, 1);

			position = format.find_first_of("%^");
			temp = format.substr(0, position);
			stream << temp;
		}
		
		stream << "\n";
	}
};
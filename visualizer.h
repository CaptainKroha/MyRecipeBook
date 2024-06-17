#pragma once
#include <vector>
#include <string>

class VisualizerBase {
public:
	virtual int show_list(const char* [], int size) = 0;
	virtual int show_list(std::vector<std::string>& list) = 0;
	virtual int show_list(std::vector<std::wstring>& list) = 0;
	virtual int show_menu(const char* [], int size) = 0;
};

class ListVisualizer :public VisualizerBase {
	virtual int show_list(const char* list[], int size) override;
	virtual int show_list(std::vector<std::string>& list) override;
	virtual int show_list(std::vector<std::wstring>& list) override;
	virtual int show_menu(const char* list[], int size) override;
};
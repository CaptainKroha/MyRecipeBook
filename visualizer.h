#pragma once

class VisualizerBase {
public:
	virtual int show_list(const char* [], int size) = 0;
	virtual int show_menu(const char* [], int size) = 0;
};

class ListVisualizer :public VisualizerBase {
	virtual int show_list(const char* list[], int size) override;
	virtual int show_menu(const char* list[], int size) override;
};
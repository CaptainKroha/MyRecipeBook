#pragma once

class VisualizerBase {
public:
	virtual int show_list(const char* [], int size) = 0;
};

class ListVisualizer :public VisualizerBase {
	virtual int show_list(const char* list[], int size) override;
};
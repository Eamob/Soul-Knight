#include"Data.h"

int g_CurrentLevel = 1;

Map g_Maps[MAX_LEVEL] =
{
	// ��һ��
	{
		MAP_WIDTH, MAP_WIDTH,	// ��ͼ���
		{
		// ��ͼԪ�ر�
		// true ��ʾ�õ��ǵ÷ֵ�
		{ { Empty },{ Wall  },{ Wall  },{ Wall  },{ Wall  },{ Wall  },{ Wall  },{ Wall  },{ Wall  },{ Wall  },{ Wall  },{ Wall  },{ Wall  },{ Wall  } },
		{ { Empty },{ Wall  },{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Wall  } },
		{ { Wall  },{ Wall  },{ Ground},{ Box   },{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Wall  } },
		{ { Wall  },{ Ground},{ Ground},{ Box   },{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Wall  } },
		{ { Wall  },{ Ground},{ Ground},{ Ground},{ Box   },{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Wall  } },
		{ { Wall  },{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Wall  } },
		{ { Wall  },{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Wall  } },
		{ { Wall  },{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Wall  } },
		{ { Wall  },{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Wall  } },
		{ { Wall  },{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Wall  } },
		{ { Wall  },{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Wall  } },
		{ { Wall  },{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Wall  } },
		{ { Wall  },{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Ground},{ Wall  } },
		{ { Wall  },{ Wall  },{ Wall  },{ Wall  },{ Wall  },{ Wall  },{ Wall  },{ Wall  },{ Wall  },{ Wall  },{ Wall  },{ Wall  },{ Wall  },{ Wall  } }
		}
	}
};

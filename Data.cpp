#include"Data.h"

int g_CurrentLevel = 1;

Map g_Maps[MAX_LEVEL] =
{
	// 第一关
	{
		MAP_WIDTH, MAP_WIDTH,	// 地图宽高
		{
		// 地图元素表
		// true 表示该点是得分点
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

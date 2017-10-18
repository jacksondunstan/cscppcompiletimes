#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
	const int NUM_CLASSES = 1000;
	const int NUM_FIELDS = 10;
	const int NUM_METHODS = 10;
	time_t timestamp = time(0);
	for (int i = 0; i < NUM_CLASSES; ++i)
	{
		// Header file
		char filename[1024];
		sprintf(filename, "../CppSource/Class%d.h", i);
		FILE* file = fopen(filename, "w");
		fprintf(file, "// Timestamp: %ld\n", timestamp);
		fprintf(file, "\n");
		fprintf(file, "// Class comment\n");
		fprintf(file, "struct Class%d\n", i);
		fprintf(file, "{\n");
		for (int j = 0; j < NUM_FIELDS; ++j)
		{
			fprintf(file, "\t// Field%d comment\n", j);
			fprintf(file, "\tint Field%d;\n", j);
			fprintf(file, "\t\n");
		}
		for (int j = 0; j < NUM_METHODS; ++j)
		{
			fprintf(file, "\t// Method%d comment\n", j);
			fprintf(file, "\tvoid Method%d();\n", j);
			fprintf(file, "\t\n");
		}
		fprintf(file, "};\n");
		fflush(file);
		fclose(file);
		
		// Implementation file
		sprintf(filename, "../CppSource/Class%d.cpp", i);
		file = fopen(filename, "w");
		fprintf(file, "// Timestamp: %ld\n", timestamp);
		fprintf(file, "\n");
		fprintf(file, "#include \"Class%d.h\"\n", i);
		for (int j = 0; j < NUM_METHODS; ++j)
		{
			fprintf(file, "// Method%d comment\n", j);
			fprintf(file, "void Class%d::Method%d()\n", i, j);
			fprintf(file, "{\n");
			fprintf(file, "}\n");
			fprintf(file, "\n");
		}
		fflush(file);
		fclose(file);
		
		// C# file
		sprintf(filename, "../Unity/Assets/Class%d.cs", i);
		file = fopen(filename, "w");
		fprintf(file, "// Timestamp: %ld\n", timestamp);
		fprintf(file, "\n");
		fprintf(file, "// Class comment\n");
		fprintf(file, "public class Class%d\n", i);
		fprintf(file, "{\n");
		for (int j = 0; j < NUM_FIELDS; ++j)
		{
			fprintf(file, "\t// Field%d comment\n", j);
			fprintf(file, "\tpublic int Field%d;\n", j);
			fprintf(file, "\t\n");
		}
		for (int j = 0; j < NUM_METHODS; ++j)
		{
			fprintf(file, "\t// Method%d comment\n", j);
			fprintf(file, "\tpublic void Method%d()\n", j);
			fprintf(file, "\t{\n");
			fprintf(file, "\t}\n");
			fprintf(file, "\t\n");
		}
		fprintf(file, "};\n");
		fflush(file);
		fclose(file);
	}
}

// Engine/Source/ArcadiaCore/Public/Math/Matrix.h
#pragma once

class Matrix {
public:
    float m[4][4];

    Matrix() {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                m[i][j] = 0.0f;
    }

    // Add any matrix operations or constructors as needed
};

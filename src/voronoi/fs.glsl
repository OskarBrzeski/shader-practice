#version 330

in vec2 fragTexCoord;

uniform vec2 point1;
uniform vec2 point2;
uniform vec2 point3;
uniform float time;

out vec4 fragColour;

float calc_dist1() {
    float dist1x = fragTexCoord.x - point1.x;
    float dist1y = fragTexCoord.y - point1.y;
    float dist1 = (dist1x * dist1x) + (dist1y * dist1y);
    return dist1;
}

float calc_dist2() {
    float dist2x = fragTexCoord.x - point2.x;
    float dist2y = fragTexCoord.y - point2.y;
    float dist2 = (dist2x * dist2x) + (dist2y * dist2y);
    return dist2;
}

float calc_dist3() {
    float dist3x = fragTexCoord.x - point3.x;
    float dist3y = fragTexCoord.y - point3.y;
    float dist3 = (dist3x * dist3x) + (dist3y * dist3y);
    return dist3;
}

float closest1(float dist1, float dist2, float dist3) {
    return float(dist1 < dist2 && dist1 < dist3);
}

float closest2(float dist1, float dist2, float dist3) {
    return float(dist2 < dist1 && dist2 < dist3);
}

float closest3(float dist1, float dist2, float dist3) {
    return float(dist3 < dist1 && dist3 < dist2);
}

void main()
{
    float dist1 = calc_dist1();
    float dist2 = calc_dist2();
    float dist3 = calc_dist3();

    float c1 = closest1(dist1, dist2, dist3);
    float c2 = closest2(dist1, dist2, dist3);
    float c3 = closest3(dist1, dist2, dist3);

    fragColour = vec4(c1, c2, c3, 1.);
    //fragColour = vec4(1., 0., 0., 1.);
}

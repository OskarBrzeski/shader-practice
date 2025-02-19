#version 330

in vec2 fragTexCoord;

uniform vec2 point1;
uniform vec2 point2;
uniform float time;

out vec4 fragColour;

void main()
{
    float x = fragTexCoord.x;
    float y = fragTexCoord.y;

    float dist1x = x - (point1.x + cos(time)/12);
    float dist1y = y - (point1.y + sin(time)/12);
    float dist1 = (dist1x * dist1x) + (dist1y * dist1y);
    float dist2x = x - (point2.x + sin(time)/12);
    float dist2y = y - (point2.y + cos(time)/12);
    float dist2 = (dist2x * dist2x) + (dist2y * dist2y);

    float circle_size = 0.00004;
    float white = float(dist1 < circle_size) + float(dist2 < circle_size);

    fragColour = vec4(float(dist1 < dist2) + white, white, float(dist1 > dist2) + white, 1.);
}

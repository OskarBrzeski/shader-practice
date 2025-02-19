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

    float dist1x = x - point1.x;
    float dist1y = y - point1.y;
    float dist1 = (dist1x * dist1x) + (dist1y * dist1y);
    float dist2x = x - point2.x;
    float dist2y = y - point2.y;
    float dist2 = (dist2x * dist2x) + (dist2y * dist2y);


    fragColour = vec4(dist1 < dist2, 0., dist1 > dist2, 1.);
}

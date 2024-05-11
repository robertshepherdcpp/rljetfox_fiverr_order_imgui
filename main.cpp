#include <imgui.h>
#include <imgui-SFML.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

int main() {
    sf::RenderWindow window(sf::VideoMode(1800, 900), "Menu");
    ImGui::SFML::Init(window);

    std::string game_mode = "Soccar";
    std::string second_combo = "Starbase ARC (aftermath)";
    bool enable_custom_maps = false;

    bool default_selected = false;
    bool beach_ball_selected = false;
    bool boomer_ball_selected = false;
    bool cubic_selected = false;
    bool demolition_selected = false;
    bool ghost_hunt_selected = false;
    bool inverted_ball_selected = false;
    bool moon_ball_selected = false;
    bool pinball_selected = false;
    bool snow_day_selected = false;
    bool spike_rush_selected = false;
    bool third_wheel_selected = false;
    bool time_warp_selected = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        ImGui::SFML::Update(window, sf::seconds(1.0f / 1000000.f));

        ImGui::SetNextWindowSize(ImVec2(1400, 900));
        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::Begin("Menu");

        if (ImGui::BeginTabBar("TopMenu"))
        {
            if (ImGui::BeginTabItem("Multiplayer"))
            {
                ImGui::Text("Host a local game");
                ImGui::Separator();

                ImGui::Text("Game mode:");
                const char* items[] = { "Soccar" }; // TODO: Add more options
                static int item_current = 0;
                ImGui::Combo("game mode", &item_current, items, IM_ARRAYSIZE(items));
                game_mode = std::string{ items[item_current] };

                ImGui::Text("Arena:");
                ImGui::SameLine();
                ImGui::Checkbox("Enable Custom Maps", &enable_custom_maps);

                const char* items_two[] = { "Starbase ARC aftermath" }; // TODO: Add more options and save to variable
                static int item_current_two = 0;
                ImGui::Combo(" ", &item_current_two, items_two, IM_ARRAYSIZE(items_two));
                ImGui::Text("Player count:");
                static int player_count = 0;
                ImGui::SliderInt("players", &player_count, 0, 10);

                ImGui::Text("Bot difficulty:");
                enum Element { Element_None, Element_Easy, Element_Medium, Element_Hard, Element_COUNT };
                static int elem = Element_None;
                const char* elems_names[Element_COUNT] = { "None", "Easy", "Medium", "Hard" };
                const char* elem_name = (elem >= 0 && elem < Element_COUNT) ? elems_names[elem] : "Unknown";
                ImGui::SliderInt("difficulty", &elem, 0, Element_COUNT - 1, elem_name);

                ImGui::NewLine();

                if (ImGui::CollapsingHeader("Team Settings"))
                {
                }
                if (ImGui::CollapsingHeader("Mutator Settings"))
                {
                    ImGui::Text("Free play:");
                    ImGui::SameLine(150);
                    enum Element { Elem_Enable, Elem_Disable, Elem_COUNT };
                    static int element = Elem_Enable;
                    const char* enable_or_disable[Elem_COUNT] = { "Enable", "Disable" };
                    const char* element_name = (element >= 0 && element < Elem_COUNT) ? enable_or_disable[element] : "Unknown";
                    ImGui::SliderInt("Free play", &element, 0, Elem_COUNT - 1, element_name);
                    ImGui::SameLine(1250);
                    ImGui::Text("Presets:");

                    ImGui::Text("Match Length:");
                    ImGui::SameLine(150);
                    enum MatchLengthElement { MatchLen_5Min, MatchLen_10Min, MatchLen_20Min, MatchLen_Unlimited, MatchLen_COUNT };
                    static int match_length_element = MatchLen_5Min;
                    const char* match_length_options[MatchLen_COUNT] = { "5 Minutes", "10 Minutes", "20 Minutes", "Unlimited" };
                    const char* match_length_element_name = (match_length_element >= 0 && match_length_element < MatchLen_COUNT) ? match_length_options[match_length_element] : "Unknown";
                    ImGui::SliderInt("MatchLength", &match_length_element, 0, MatchLen_COUNT - 1, match_length_element_name);
                    ImGui::SameLine(1250);
                    if (ImGui::Button("Beach Ball"))
                    {
                        beach_ball_selected = true;
                    }


                    ImGui::Text("Max Score:");
                    ImGui::SameLine(150);
                    enum MaxScoreElement { MaxScore_Default, MaxScore_1Goal, MaxScore_3Goals, MaxScore_5Goals, MaxScore_7Goals, MaxScore_Unlimited, MaxScore_COUNT };
                    static int max_score_element = MaxScore_Default;
                    const char* max_score_options[MaxScore_COUNT] = { "Default", "1 Goal", "3 Goals", "5 Goals", "7 Goals", "Unlimited" };
                    const char* max_score_element_name = (max_score_element >= 0 && max_score_element < MaxScore_COUNT) ? max_score_options[max_score_element] : "Unknown";
                    ImGui::SliderInt("MaxScore", &max_score_element, 0, MaxScore_COUNT - 1, max_score_element_name);
                    ImGui::SameLine(1250);
                    if (ImGui::Button("Boomer Ball"))
                    {
                        boomer_ball_selected = true;
                    }

                    ImGui::Text("Overtime:");
                    ImGui::SameLine(150);
                    enum OvertimeElement { Overtime_Unlimited, Overtime_Plus5Max_FirstScore, Overtime_Plus5Max_RandomTeam, Overtime_COUNT };
                    static int overtime_element = Overtime_Unlimited;
                    const char* overtime_options[Overtime_COUNT] = { "Unlimited", "+5 Max, First Score", "+5 Max, Random Team" };
                    const char* overtime_element_name = (overtime_element >= 0 && overtime_element < Overtime_COUNT) ? overtime_options[overtime_element] : "Unknown";
                    ImGui::SliderInt("Overtime", &overtime_element, 0, Overtime_COUNT - 1, overtime_element_name);
                    ImGui::SameLine(1250);
                    if (ImGui::Button("Cubic"))
                    {
                        cubic_selected = true;
                    }


                    ImGui::Text("Max Time Limit:");
                    ImGui::SameLine(150);
                    enum MaxTimeLimitElement { MaxTime_Default, MaxTime_11Minutes, MaxTime_COUNT };
                    static int max_time_limit_element = MaxTime_Default;
                    const char* max_time_limit_options[MaxTime_COUNT] = { "Default", "11 Minutes" };
                    const char* max_time_limit_element_name = (max_time_limit_element >= 0 && max_time_limit_element < MaxTime_COUNT) ? max_time_limit_options[max_time_limit_element] : "Unknown";
                    ImGui::SliderInt("MaxTimeLimit", &max_time_limit_element, 0, MaxTime_COUNT - 1, max_time_limit_element_name);
                    ImGui::SameLine(1250);
                    if (ImGui::Button("Demolition"))
                    {
                        demolition_selected = true;
                    }

                    ImGui::Text("Series Length:");
                    ImGui::SameLine(150);
                    enum SeriesLengthElement { SeriesLength_Unlimited, SeriesLength_3Games, SeriesLength_5Games, SeriesLength_7Games, SeriesLength_COUNT };
                    static int series_length_element = SeriesLength_Unlimited;
                    const char* series_length_options[SeriesLength_COUNT] = { "Unlimited", "3 Games", "5 Games", "7 Games" };
                    const char* series_length_element_name = (series_length_element >= 0 && series_length_element < SeriesLength_COUNT) ? series_length_options[series_length_element] : "Unknown";
                    ImGui::SliderInt("SeriesLength", &series_length_element, 0, SeriesLength_COUNT - 1, series_length_element_name);
                    ImGui::SameLine(1250);
                    if (ImGui::Button("Ghost Hunt"))
                    {
                        ghost_hunt_selected = true;
                    }

                    ImGui::Text("Game Speed:");
                    ImGui::SameLine(150);
                    enum GameSpeedElement { GameSpeed_Default, GameSpeed_SloMo, GameSpeed_TimeWarp, GameSpeed_COUNT };
                    static int game_speed_element = GameSpeed_Default;
                    const char* game_speed_options[GameSpeed_COUNT] = { "Default", "Slo-mo", "Time Warp" };
                    const char* game_speed_element_name = (game_speed_element >= 0 && game_speed_element < GameSpeed_COUNT) ? game_speed_options[game_speed_element] : "Unknown";
                    ImGui::SliderInt("GameSpeed", &game_speed_element, 0, GameSpeed_COUNT - 1, game_speed_element_name);
                    ImGui::SameLine(1250);
                    if (ImGui::Button("Inverted Ball"))
                    {
                        inverted_ball_selected = true;
                    }

                    ImGui::Text("Ball Max Speed:");
                    ImGui::SameLine(150);
                    enum BallMaxSpeedElement { BallMaxSpeed_Default, BallMaxSpeed_Slow, BallMaxSpeed_Fast, BallMaxSpeed_SuperFast, BallMaxSpeed_COUNT };
                    static int ball_max_speed_element = BallMaxSpeed_Default;
                    const char* ball_max_speed_options[BallMaxSpeed_COUNT] = { "Default", "Slow", "Fast", "Super Fast" };
                    const char* ball_max_speed_element_name = (ball_max_speed_element >= 0 && ball_max_speed_element < BallMaxSpeed_COUNT) ? ball_max_speed_options[ball_max_speed_element] : "Unknown";
                    ImGui::SliderInt("BallMaxSpeed", &ball_max_speed_element, 0, BallMaxSpeed_COUNT - 1, ball_max_speed_element_name);
                    ImGui::SameLine(1250);
                    if (ImGui::Button("Moon ball"))
                    {
                        moon_ball_selected = true;
                    }

                    ImGui::Text("Ball Type:");
                    ImGui::SameLine(150);
                    enum BallTypeElement { BallType_Default, BallType_Cube, BallType_Puck, BallType_BasketBall, BallType_BeachBall, BallType_Anniversary, BallType_HauntedBall, BallType_COUNT };
                    static int ball_type_element = BallType_Default;
                    const char* ball_type_options[BallType_COUNT] = { "Default", "Cube", "Puck", "BasketBall", "BeachBall", "Anniversary", "HauntedBall" };
                    const char* ball_type_element_name = (ball_type_element >= 0 && ball_type_element < BallType_COUNT) ? ball_type_options[ball_type_element] : "Unknown";
                    ImGui::SliderInt("BallType", &ball_type_element, 0, BallType_COUNT - 1, ball_type_element_name);
                    ImGui::SameLine(1250);
                    if (ImGui::Button("Pinball"))
                    {
                        pinball_selected = true;
                    }

                    ImGui::Text("Ball Gravity:");
                    ImGui::SameLine(150);
                    enum BallGravityElement { BallGravity_Default, BallGravity_Low, BallGravity_High, BallGravity_SuperHigh, BallGravity_COUNT };
                    static int ball_gravity_element = BallGravity_Default;
                    const char* ball_gravity_options[BallGravity_COUNT] = { "Default", "Low", "High", "Super High" };
                    const char* ball_gravity_element_name = (ball_gravity_element >= 0 && ball_gravity_element < BallGravity_COUNT) ? ball_gravity_options[ball_gravity_element] : "Unknown";
                    ImGui::SliderInt("BallGravity", &ball_gravity_element, 0, BallGravity_COUNT - 1, ball_gravity_element_name);
                    ImGui::SameLine(1250);
                    if (ImGui::Button("Snow day"))
                    {
                        snow_day_selected = true;
                    }

                    ImGui::Text("Ball Physics:");
                    ImGui::SameLine(150);
                    enum BallPhysicsElement { BallPhysics_Default, BallPhysics_Light, BallPhysics_Heavy, BallPhysics_SuperLight, BallPhysics_CurveBall, BallPhysics_BeachBallCurve, BallPhysics_COUNT };
                    static int ball_physics_element = BallPhysics_Default;
                    const char* ball_physics_options[BallPhysics_COUNT] = { "Default", "Light", "Heavy", "Super Light", "CurveBall", "Beach Ball Curve" };
                    const char* ball_physics_element_name = (ball_physics_element >= 0 && ball_physics_element < BallPhysics_COUNT) ? ball_physics_options[ball_physics_element] : "Unknown";
                    ImGui::SliderInt("BallPhysics", &ball_physics_element, 0, BallPhysics_COUNT - 1, ball_physics_element_name);
                    ImGui::SameLine(1250);
                    if (ImGui::Button("Spike rush"))
                    {
                        spike_rush_selected = true;
                    }

                    ImGui::Text("Ball Size:");
                    ImGui::SameLine(150);
                    enum BallSizeElement { BallSize_Default, BallSize_Small, BallSize_Medium, BallSize_Large, BallSize_Gigantic, BallSize_COUNT };
                    static int ball_size_element = BallSize_Default;
                    const char* ball_size_options[BallSize_COUNT] = { "Default", "Small", "Medium", "Large", "Gigantic" };
                    const char* ball_size_element_name = (ball_size_element >= 0 && ball_size_element < BallSize_COUNT) ? ball_size_options[ball_size_element] : "Unknown";
                    ImGui::SliderInt("BallSize", &ball_size_element, 0, BallSize_COUNT - 1, ball_size_element_name);
                    ImGui::SameLine(1250);
                    if (ImGui::Button("Third Wheel"))
                    {
                        third_wheel_selected = true;
                    }

                    ImGui::Text("Ball Bounciness:");
                    ImGui::SameLine(150);
                    enum BallBouncinessElement { BallBounciness_Default, BallBounciness_Low, BallBounciness_High, BallBounciness_SuperHigh, BallBounciness_COUNT };
                    static int ball_bounciness_element = BallBounciness_Default;
                    const char* ball_bounciness_options[BallBounciness_COUNT] = { "Default", "Low", "High", "Super High" };
                    const char* ball_bounciness_element_name = (ball_bounciness_element >= 0 && ball_bounciness_element < BallBounciness_COUNT) ? ball_bounciness_options[ball_bounciness_element] : "Unknown";
                    ImGui::SliderInt("BallBounciness", &ball_bounciness_element, 0, BallBounciness_COUNT - 1, ball_bounciness_element_name);
                    ImGui::SameLine(1250);
                    if (ImGui::Button("Time Warp"))
                    {
                        time_warp_selected = true;
                    }

                    ImGui::Text("Number Of Balls:");
                    ImGui::SameLine(150);
                    enum NumberOfBallsElement { NumberOfBalls_One, NumberOfBalls_Two, NumberOfBalls_Four, NumberOfBalls_Six, NumberOfBalls_COUNT };
                    static int number_of_balls_element = NumberOfBalls_One;
                    const char* number_of_balls_options[NumberOfBalls_COUNT] = { "One", "Two", "Four", "Six" };
                    const char* number_of_balls_element_name = (number_of_balls_element >= 0 && number_of_balls_element < NumberOfBalls_COUNT) ? number_of_balls_options[number_of_balls_element] : "Unknown";
                    ImGui::SliderInt("NumberOfBalls", &number_of_balls_element, 0, NumberOfBalls_COUNT - 1, number_of_balls_element_name);

                    ImGui::Text("Boosts Amount:");
                    ImGui::SameLine(150);
                    enum BoostsAmountElement { BoostsAmount_Default, BoostsAmount_NoBoost, BoostsAmount_Unlimited, BoostsAmount_RechargeSlow, BoostsAmount_RechargeFast, BoostsAmount_COUNT };
                    static int boosts_amount_element = BoostsAmount_Default;
                    const char* boosts_amount_options[BoostsAmount_COUNT] = { "Default", "No Boost", "Unlimited", "Recharge (slow)", "Recharge (fast)" };
                    const char* boosts_amount_element_name = (boosts_amount_element >= 0 && boosts_amount_element < BoostsAmount_COUNT) ? boosts_amount_options[boosts_amount_element] : "Unknown";
                    ImGui::SliderInt("BoostsAmount", &boosts_amount_element, 0, BoostsAmount_COUNT - 1, boosts_amount_element_name);
                    ImGui::SameLine(1250);
                    if (ImGui::Button("Save Preset"))
                    {
                        // TODO handle how to save the presets
                    }

                    ImGui::Text("Rumble:");
                    ImGui::SameLine(150);
                    enum RumbleElement { Rumble_None, Rumble_Default, Rumble_Slow, Rumble_Civilized, Rumble_DestructionDerby, Rumble_SpringLoaded, Rumble_SpikesOnly, Rumble_Rugby, Rumble_HauntedBallBeam, Rumble_TacticalRumble, Rumble_COUNT };
                    static int rumble_element = Rumble_None;
                    const char* rumble_options[Rumble_COUNT] = { "None", "Default", "Slow", "Civilized", "Destruction Derby", "Spring Loaded", "Spikes Only", "Rugby", "Haunted Ball Beam", "Tactical Rumble" };
                    const char* rumble_element_name = (rumble_element >= 0 && rumble_element < Rumble_COUNT) ? rumble_options[rumble_element] : "Unknown";
                    ImGui::SliderInt("Rumble", &rumble_element, 0, Rumble_COUNT - 1, rumble_element_name);

                    ImGui::Text("Boost Strength:");
                    ImGui::SameLine(150);
                    enum BoostStrengthElement { BoostStrength_1X, BoostStrength_1_5X, BoostStrength_2X, BoostStrength_10X, BoostStrength_COUNT };
                    static int boost_strength_element = BoostStrength_1X;
                    const char* boost_strength_options[BoostStrength_COUNT] = { "1X", "1.5X", "2X", "10X" };
                    const char* boost_strength_element_name = (boost_strength_element >= 0 && boost_strength_element < BoostStrength_COUNT) ? boost_strength_options[boost_strength_element] : "Unknown";
                    ImGui::SliderInt("BoostStrength", &boost_strength_element, 0, BoostStrength_COUNT - 1, boost_strength_element_name);

                    ImGui::Text("Gravity:");
                    ImGui::SameLine(150);
                    enum GravityElement { Gravity_Default, Gravity_Low, Gravity_High, Gravity_SuperHigh, Gravity_Reverse, Gravity_COUNT };
                    static int gravity_element = Gravity_Default;
                    const char* gravity_options[Gravity_COUNT] = { "Default", "Low", "High", "Super High", "Reverse" };
                    const char* gravity_element_name = (gravity_element >= 0 && gravity_element < Gravity_COUNT) ? gravity_options[gravity_element] : "Unknown";
                    ImGui::SliderInt("Gravity", &gravity_element, 0, Gravity_COUNT - 1, gravity_element_name);

                    ImGui::Text("Demolish:");
                    ImGui::SameLine(150);
                    enum DemolishElement { Demolish_Default, Demolish_Disabled, Demolish_FriendlyFire, Demolish_OnContact, Demolish_OnContact_FF, Demolish_COUNT };
                    static int demolish_element = Demolish_Default;
                    const char* demolish_options[Demolish_COUNT] = { "Default", "Disabled", "Friendly Fire", "On Contact", "On Contact (FF)" };
                    const char* demolish_element_name = (demolish_element >= 0 && demolish_element < Demolish_COUNT) ? demolish_options[demolish_element] : "Unknown";
                    ImGui::SliderInt("Demolish", &demolish_element, 0, Demolish_COUNT - 1, demolish_element_name);

                    ImGui::Text("Respawn Time:");
                    ImGui::SameLine(150);
                    enum RespawnTimeElement { RespawnTime_3Seconds, RespawnTime_2Seconds, RespawnTime_1Second, RespawnTime_DisableGoalReset, RespawnTime_COUNT };
                    static int respawn_time_element = RespawnTime_3Seconds;
                    const char* respawn_time_options[RespawnTime_COUNT] = { "3 Seconds", "2 Seconds", "1 Second", "Disable Goal Reset" };
                    const char* respawn_time_element_name = (respawn_time_element >= 0 && respawn_time_element < RespawnTime_COUNT) ? respawn_time_options[respawn_time_element] : "Unknown";
                    ImGui::SliderInt("RespawnTime", &respawn_time_element, 0, RespawnTime_COUNT - 1, respawn_time_element_name);

                    ImGui::Text("Bot Loadouts:");
                    ImGui::SameLine(150);
                    enum BotLoadoutsElement { BotLoadouts_Default, BotLoadouts_Random, BotLoadouts_COUNT };
                    static int bot_loadouts_element = BotLoadouts_Default;
                    const char* bot_loadouts_options[BotLoadouts_COUNT] = { "Default", "Random" };
                    const char* bot_loadouts_element_name = (bot_loadouts_element >= 0 && bot_loadouts_element < BotLoadouts_COUNT) ? bot_loadouts_options[bot_loadouts_element] : "Unknown";
                    ImGui::SliderInt("BotLoadouts", &bot_loadouts_element, 0, BotLoadouts_COUNT - 1, bot_loadouts_element_name);

                    ImGui::Text("Audio:");
                    ImGui::SameLine(150);
                    enum AudioElement { Audio_Default, Audio_Haunted, Audio_COUNT };
                    static int audio_element = Audio_Default;
                    const char* audio_options[Audio_COUNT] = { "Default", "Haunted" };
                    const char* audio_element_name = (audio_element >= 0 && audio_element < Audio_COUNT) ? audio_options[audio_element] : "Unknown";
                    ImGui::SliderInt("Audio", &audio_element, 0, Audio_COUNT - 1, audio_element_name);

                    ImGui::Text("Game Event:");
                    ImGui::SameLine(150);
                    enum GameEventElement { GameEvent_Default, GameEvent_Haunted, GameEvent_Rugby, GameEvent_COUNT };
                    static int game_event_element = GameEvent_Default;
                    const char* game_event_options[GameEvent_COUNT] = { "Default", "Haunted", "Rugby" };
                    const char* game_event_element_name = (game_event_element >= 0 && game_event_element < GameEvent_COUNT) ? game_event_options[game_event_element] : "Unknown";
                    ImGui::SliderInt("GameEvent", &game_event_element, 0, GameEvent_COUNT - 1, game_event_element_name);
                }
                if (ImGui::CollapsingHeader("Advanced Settings"))
                {
                }

                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem("In Game Mods"))
            {
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem("Game Modes"))
            {
                ImGui::EndTabItem();
            }
            ImGui::EndTabBar();
        }

        ImGui::NewLine();

        if (ImGui::Button("Host"))
        {
            // TODO: implement response.
        }

        ImGui::End();

        {
        ImGui::SetNextWindowSize(ImVec2(400, 900));
        ImGui::SetNextWindowPos(ImVec2(1400, 0));
        ImGui::Begin("Join a local game");

        ImGui::Text("IP Address:");
        static char ip[128] = "";
        ImGui::InputText("ip", ip, IM_ARRAYSIZE(ip));
        ImGui::NewLine();

        ImGui::Text("Port:");
        static char port[128] = "";
        ImGui::InputText("port", port, IM_ARRAYSIZE(port));
        ImGui::NewLine();

        ImGui::Text("Password:");
        static char password[128] = "";
        ImGui::InputText("password", password, IM_ARRAYSIZE(password));
        ImGui::NewLine();

        ImGui::End();
        }

        window.clear();
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();

    return 0;
}
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class mainLevelController : MonoBehaviour
{
    NavMeshSurface2d NavMesh;
    [SerializeField] roomPrefabs[] roomPrefabs;
    private void Awake()
    {
        NavMesh = GameObject.Find("NavMesh Surface").GetComponent<NavMeshSurface2d>();
        //NavMesh.BuildNavMesh();
        //Instantiate(roomPrefabs[0].rooms_type[0]);
        generate_level(Random.Range(4, 8));
    }

    private void generate_level(int roomCount)
    {
        bool[, ] field = new bool[5,5];
        Vector2Int current_vector = new Vector2Int(2,2);
        int usedPrefabs = Random.Range(0, roomPrefabs.Length);
        Vector2 room_pos = new Vector2(0,0);
        GameObject thisShit = Instantiate(roomPrefabs[0].rooms_type[0], transform);
        thisShit.transform.position = new Vector3(room_pos.x, room_pos.y, 0);
        while (roomCount > 0)
        {
            int z = Random.Range(0, 4);
            if(current_vector.x > field.GetLength(current_vector.x))
            switch (z){
                case 0:
                    if (field[current_vector.x, current_vector.y + 1] == false)
                    {
                        field[current_vector.x, current_vector.y + 1] = true;

                    }
                    break;
                case 1:
                    if (field[current_vector.x + 1, current_vector.y] == false)
                    {
                        field[current_vector.x + 1, current_vector.y] = true;
                    }
                    break;
                case 2:
                    if (field[current_vector.x, current_vector.y - 1] == false)
                    {
                        field[current_vector.x, current_vector.y - 1] = true;
                    }
                    break;
                case 3:
                    if (field[current_vector.x - 1, current_vector.y] == false)
                    {
                        field[current_vector.x - 1, current_vector.y] = true;
                    }
                    break;
            }
        }
    }
}
[System.Serializable]
public struct roomPrefabs
{
    public GameObject[] rooms_type;
    public GameObject[] units;
    public GameObject[] weapons;
}

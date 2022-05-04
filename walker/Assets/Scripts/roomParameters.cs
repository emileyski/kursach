using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class roomParameters : MonoBehaviour
{
    NavMeshSurface2d NavMesh;
    public base_unit[] unitsInRoom;
    int x = 0, enemy_waves = 0;
    [SerializeField] GameObject[] unit_prefab;
    [SerializeField] private GameObject chest_prefab;
    void Start()
    {
        NavMesh = GameObject.Find("NavMesh Surface").GetComponent<NavMeshSurface2d>();
        GameObject hall_checker = transform.Find("hall_checker").gameObject;
        hall_checker.transform.position += new Vector3(0, 20.5f);

    }
    public void activation()
    {
        transform.Find("Gates_0").gameObject.SetActive(true);
        transform.Find("Gates_1").gameObject.SetActive(true);
        NavMesh.BuildNavMesh();
        for(int i = 0; i<unitsInRoom.Length; i++)
        {
            unitsInRoom[i].activation_deactivation(true);
        }
        transform.Find("Floor").GetComponent<BoxCollider2D>().enabled = false;
    }
    public void someUnitIsZdoh()
    {
        x++;
        if (x >= unitsInRoom.Length)
        {
            unitsInRoom = new base_unit[0];
            enemy_waves++;
            print(enemy_waves);

            if(enemy_waves >= 3)
            {
                transform.Find("Gates_0").gameObject.SetActive(false);
                transform.Find("Gates_1").gameObject.SetActive(false);
                Instantiate(chest_prefab, transform.position + new Vector3(Random.Range(-5, 6), Random.Range(-5, 6), 0), Quaternion.identity);
            }
            else
            {
                int spawnCount = Random.Range(2, 5);
                for (int j = 0; j < spawnCount; j++)
                {
                    Instantiate(unit_prefab[Random.Range(0, unit_prefab.Length)], transform.position + new Vector3(Random.Range(-5, 6), Random.Range(-5, 6), 0), Quaternion.identity);
                }
                Invoke("activation", 0.2f);
                x = 0;
            }
        }
    }
}

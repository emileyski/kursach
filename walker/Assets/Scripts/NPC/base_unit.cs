using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;


public class base_unit : MonoBehaviour
{
    [SerializeField] protected int lifeCount;//колво жизней
    [SerializeField] roomParameters thisRoom;//ссылка на скрипт рума, в котором находится юнит
    [SerializeField] protected float atackRange, cooldown;//пожилые флоты для рэнжи юнита и кулдауна/перезарядки

    protected NavMeshAgent agent;// Для навигации додика
    protected Animator animator;//для управления анимацией
    protected GameObject player, Weapon;//ссылка на главного персонажа, с которым будем взаимодействовать, ссылка на объект оружия
    protected bool isDied = false;

    protected virtual void Start()
    { 
        //начало кода для идентификации комнаты
        GameObject[] identification = GameObject.FindGameObjectsWithTag("currentRoom");
        float x = Vector3.Distance(transform.position, identification[0].transform.position);
        thisRoom = identification[0].GetComponent<roomParameters>();
        for (int i = 0; i < identification.Length; i++)
        {
            if(x > Vector3.Distance(identification[i].transform.position, transform.position))
            {
                x = Vector3.Distance(identification[i].transform.position, transform.position);
                thisRoom = identification[i].GetComponent<roomParameters>();
            }
        }
        base_unit[] z = thisRoom.unitsInRoom;
        thisRoom.unitsInRoom = new base_unit[thisRoom.unitsInRoom.Length + 1];
        for (int i = 0; i < thisRoom.unitsInRoom.Length - 1; i++)
        {
            thisRoom.unitsInRoom[i] = z[i];
        }
        thisRoom.unitsInRoom[thisRoom.unitsInRoom.Length - 1] = gameObject.GetComponent<base_unit>();
        //код для идентефикации в комнате(конец)

        //получаем нужные компоненты
        animator = GetComponent<Animator>();
        agent = GetComponent<NavMeshAgent>();
        player = GameObject.Find("Player");
        Weapon = transform.Find("Weapon").gameObject;
        //настраиваем navmeshAgent
        agent.updateRotation = false;
        agent.updateUpAxis = false;
        agent.isStopped = true;
        Physics2D.queriesStartInColliders = false;
    }
    // Update is called once per frame
    protected virtual void Update()
    {
        if (!isDied)
        {
            moveing();
        }
    }
    public virtual void activation_deactivation(bool isActivation)
    {
        if (isActivation)
        {
            agent.isStopped = false;
            animator.SetTrigger("isActivated");
        }
        else
        {
            animator.SetTrigger("isDied");
            Weapon.SetActive(false);
            GetComponent<CapsuleCollider2D>().enabled = false;
            isDied = true;
            thisRoom.someUnitIsZdoh();
        }
    }
    protected virtual void moveing()
    {
        agent.SetDestination(player.transform.position);
        transform.localScale = (player.transform.position.x > transform.position.x) ? new Vector3(1, 1, 1) : new Vector3(-1, 1, 1);
    }
    protected virtual IEnumerator Atack(bool toAtack)
    {
        yield return new WaitForSeconds(0f);
    }
    protected virtual void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.GetComponent<weaponController>())
        {
            lifeCount -= collision.GetComponent<weaponController>().damageCount;
            if (lifeCount <= 0)
            {
                activation_deactivation(false);
            }
        }
    }
}
